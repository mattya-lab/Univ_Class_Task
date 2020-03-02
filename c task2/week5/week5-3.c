#include <stdio.h>
#include <stdlib.h>

struct data {
    char key;
    struct data* next;
};

struct queue { struct data* top, * rear; };

int main(void)
{
    struct queue q;

    q.top = (struct  data*)malloc(sizeof(struct data));
    q.top->key = 'a';
    q.top->next = NULL;
    q.rear = q.top;

    q.rear->next = (struct data*)malloc(sizeof(struct data));
    q.rear = q.rear->next;
    q.rear->key = 'b';
    q.rear->next = NULL;

    q.rear->next = (struct data*)malloc(sizeof(struct data));
    q.rear = q.rear->next;
    q.rear->key = 'c';
    q.rear->next = NULL;

    printf("%c\n", q.top->key);
    printf("%c\n", q.top->next->key);
    printf("%c\n", q.rear->key);

    free(q.top);
    free(q.top->next);
    free(q.top->next->next);
    return 0;
}