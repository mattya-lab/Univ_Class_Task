#include <stdio.h>
#include <stdlib.h>

struct data{
  char key;
  struct data *next;
};

void push(struct data **top, char key);
char pop (struct data **top);
void print_stack_list(struct data *top);

int main(void)
{
    struct data* top = NULL;
    char x;

    push(&top, 'a');
    print_stack_list(top);
    push(&top, 'b');
    print_stack_list(top);
    push(&top, 'c');
    print_stack_list(top);

    x = pop(&top);
    printf("The character popped is %c.\n", x);
    print_stack_list(top);

    x = pop(&top);
    printf("The character popped is %c.\n", x);
    print_stack_list(top);

    x = pop(&top);
    printf("The character popped is %c.\n", x);
    print_stack_list(top);
    return 0;
}

void print_stack_list(struct data* top)
{
    struct data* x;
    x = top;

    if (x == NULL) {
        return;
    }
    else {
        printf("%c<---TOP\n", x->key);
        while (x->next != NULL) {
            x = x->next;
            printf("%c\n", x->key);
        }
    }
}

void push(struct data** top, char key)
{
    struct data* t;
    t = (struct data*)malloc(sizeof(struct data));
    t->key = key;
    t->next = (*top);
    (*top) = t;
}

char pop(struct data** top)
{
    struct data* s;
    char u;

    if (*top == NULL)
        return '\0';
    else {
        s = (*top);
        u = s->key;
        (*top) = s->next;
        free(s);
        return u;
    }
}