#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
  char key;
  struct data *next;
};

struct queue{
  struct data *top;
  struct data *rear;
};

struct data {
    char key;
    struct data* next;
};

struct queue {
    struct data* top;
    struct data* rear;
};

void print_queue_list(struct queue q);
void enqueue(struct queue* q, char key);

int main(void)
{
    struct queue q = { NULL, NULL };

    enqueue(&q, 'a');
    print_queue_list(q);
    enqueue(&q, 'b');
    print_queue_list(q);
    enqueue(&q, 'c');
    print_queue_list(q);

    return 0;
}

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

void enqueue(struct queue* q, char key) {
    struct data* p = NULL;
    p = (struct data)malloc(sizeof(struct data));
    p->key = key;
    p->next = NULL;
    if (q->top == NULL) {
        q->top = p; q->rear = p;
    }
    else {
        q->rear->next = p;
        q->rear = p;
    }
}
