#include <stdio.h>
#include <stdlib.h>

struct data {
    char key;
    struct data* next;

};

int main(void)
{
    struct data* top = NULL;

    top = (struct data*)malloc(sizeof(struct data));
    top->key = 'a';
    top->next = NULL;

    top->next = (struct data*)malloc(sizeof(struct data));
    top->next->key = 'b';
    top->next->next = NULL;

    top->next->next = (struct data*)malloc(sizeof(struct data));
    top->next->next->key = 'c';
    top->next->next->next = NULL;

    printf("%c\n", top->key);
    printf("%c\n", top->next->key);
    printf("%c\n", top->next->next->key);

    free(top->next->next);
    free(top->next);
    free(top);

    return 0;
}
