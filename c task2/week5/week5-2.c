#include <stdio.h>
#include <stdlib.h>

struct data {
    char key;
    struct data* next;
};

void print_stack_list(struct data* top)
{
    int i = 0;
    struct data* cur;
    cur = top;

    while (1) {
        printf("%c", cur->key);

        if (i == 0) {
            printf("<---TOP");
        }
        printf("\n");
        if (cur->next == NULL) 
            break; 
        cur = cur->next;
        i++;
    }
}

int main(void)
{
    struct data* top = NULL;

    top = (struct data*)malloc(sizeof(struct data));
    top->key = 'a';
    top->next = NULL;

    top->next = (struct data*)malloc(sizeof(struct data));
    top->next->key = 'b';
    top->next->next = top;
    top = top->next;
    top->next->next = NULL;

    top->next->next = (struct data*)malloc(sizeof(struct data));
    top->next->next->key = 'c';
    top->next->next->next = top;
    top = top->next->next;
    top->next->next->next = NULL;


    top->next->next->next = (struct data*)malloc(sizeof(struct data));
    top->next->next->next->key = 'd';
    top->next->next->next->next = top;
    top = top->next->next->next;
    top->next->next->next->next = NULL;

    print_stack_list(top);

    free(top->next->next->next);
    free(top->next->next);
    free(top->next);
    free(top);

    return 0;
}