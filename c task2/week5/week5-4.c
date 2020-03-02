#include<stdio.h>
#include<stdlib.h>

struct data {
    char key;
    struct data* next;
};

struct queue {
    struct data* top;
    struct data* rear;
};

void print_queue_list(struct queue q)
{
    printf("%c<---TOP\n", q.top->key);
    q.top = q.top->next;
    while (q.top != NULL) {
        printf("%c", q.top->key);
        if (q.top->next == NULL)
            printf("<----REAR\n");
        else
            putchar('\n');
        q.top = q.top->next;
    }
}

int main(void)
{
    struct queue q;

    q.top = (struct data*)malloc(sizeof(struct data));
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

    q.rear->next = (struct data*)malloc(sizeof(struct data));
    q.rear = q.rear->next;
    q.rear->key = 'd';
    q.rear->next = NULL;

    print_queue_list(q);

    free(q.top);
    free(q.top->next);
    free(q.top->next->next);
    free(q.top->next->next->next);
    return 0;
}


