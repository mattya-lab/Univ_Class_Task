#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
  char key;
  struct data *next;
};

struct queue{
  struct data *top,  *rear;
};

struct data {
    char key;
    struct data* next;
};

struct queue {
    struct data* top, * rear;
};

void print_queue_list(struct queue q)
{
    int flag = 0;
    struct queue cur;
    cur = q;

    while (1) {
        if (cur.top == NULL) {
            printf("<---TOP<---REAR\n"); break;
        }
        else {
            printf("%c", cur.top->key);
            if (flag == 0) {
                printf("<---TOP");
            }
            if (cur.top->next == NULL) {
                printf("<---REAR\n");
                break;
            }
            printf("\n");
            cur.top = cur.top->next;  flag = 1;
        }
    }
}

void enqueue(struct queue* q, char key)
{
    struct data* p1 = NULL;

    p1 = (struct data)malloc(sizeof(struct data));/*メモリ確保*/
    p1->key = key; p1->next = NULL;
    if (q->top == NULL) {
        q->top = p1; q->rear = p1;
    }
    else {
        q->rear->next = p1; q->rear = p1;
    }
}

char dequeue(struct queue* q) {
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

int main(void) {
    struct queue q = { NULL, NULL };
    char x, y;
    while (1) {
        printf("Input a character(0 : Exit, 1 : Dequeue Other : Enqueue)");
        scanf("%c", &x); getchar();

        if (x == '0') { 
            printf("Exit\n"); 
            break; 
        }
        else if (x == '1') {
            y = dequeue(&q);
            printf("The character dequeue is %c.\n", y);
            print_queue_list(q);
        }
        else {
            enqueue(&q, x); print_queue_list(q);
        }
    }
    return 0;
}