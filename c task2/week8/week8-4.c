#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
    if (q.top == NULL) {}
    else {
        printf("%c<---TOP\n", q.top->key);
        q.top = q.top->next;
        while (q.top != NULL) {
            printf("%c", q.top->key);
            if (q.top->next == NULL)
                printf("<----REAR");
            putchar('\n');
            q.top = q.top->next;
        }
    }
}

void enqueue(struct queue* q, char key) 
{
    struct data* p1 = NULL;

    p1 = (struct data)malloc(sizeof(struct data));
    p1->key = key;
    p1->next = NULL;
    if (q->top == NULL) {
        q->top = p1; q->rear = p1;
    }
    else {
        q->rear->next = p1;
        q->rear = p1;
    }
}
char dequeue(struct queue* q)
{
    struct data* p2;
    char x;
    if (q->top == NULL)
        x = '\0';
    else {
        x = q->top->key;
        p2 = q->top;
        q->top = p2->next;
        free(p2);
    }
    return x;
}
int main(void)
{
    struct queue q = { NULL, NULL };
    char x;

    enqueue(&q, 'a');
    print_queue_list(q);
    enqueue(&q, 'b');
    print_queue_list(q);
    enqueue(&q, 'c');
    print_queue_list(q);

    x = dequeue(&q);
    printf("The character dequeued is %c.\n", x);
    print_queue_list(q);
    x = dequeue(&q);
    printf("The character dequeued is %c.\n", x);
    print_queue_list(q);
    x = dequeue(&q);
    printf("The character dequeued is %c.\n", x);
    print_queue_list(q);;

    return 0;
}
