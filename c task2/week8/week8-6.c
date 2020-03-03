#include <stdio.h>
#include <stdlib.h>

struct data {
    char key;
    struct data* next;
};

void print_stack_list(struct data* top) {
    struct data* x;
    x = top;
    if (x == NULL) return;
    else {
        printf("%c<---TOP\n", x->key);
        while (x->next != NULL) {
            x = x->next; printf("%c\n", x->key);
        }
    }
}

void push(struct data** top, char key) {
    struct data* t;
    t = (struct data*)malloc(sizeof(struct data));
    t->key = key; t->next = (*top);
    (*top) = t;
}

char pop(struct data** top) {
    struct data* s;
    char u;
    if (*top == NULL) return '\0';
    else {
        s = (*top); u = s->key;
        (*top) = s->next;
        free(s);
        return u;
    }
}

int main(void) {
    struct data* top = NULL;
    char x/*pop_up*/, y/*push_down*/;
    while (1) {
        printf("Input a character (0 : Exit, 1 : push_down, other : pop_up)");
        scanf("%c", &x); getchar();
        if (x == '0') { printf("Exit\n"); break; }
        else if (x == '1') {
            y = pop(&top); printf("The character popped %c.\n", y);
            print_stack_list(top);
        }
        else {
            push(&top, x);
            print_stack_list(top);
        }
    }
    return 0;
}