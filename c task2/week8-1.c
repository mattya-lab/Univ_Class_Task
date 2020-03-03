#include <stdio.h>
#include <stdlib.h>

struct data {
    char key;
    struct data* next;

};


void print_stack_list(struct data* top)
{
    struct data* x;
    x = top;
    if (x == NULL) {
        return;
    }
    printf("%c<---TOP\n", x->key);
    while (x->next != NULL) {
        x = x->next;
        printf("%c\n", x->key);
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

int main(void)
{
    struct data* top = NULL;

    push(&top, 'a');
    print_stack_list(top);

    push(&top, 'b');
    print_stack_list(top);

    push(&top, 'c');
    print_stack_list(top);

    return 0;
}

