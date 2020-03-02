#include<stdio.h>

void printf_queue_ary(char* q, int top, int rear);
void enqueue(char c, char* q, int* top, int* rear);
char dequeue(char* q, int* top, int* rear);

int main(void)
{

    char q[15];
    int top = 0, rear = 0;
    char x, y;

    q[rear] = 'a', rear++;
    q[rear] = 'b', rear++;
    q[rear] = 'c', rear++;
    q[rear] = 'd', rear++;

    printf("Input a character: "); scanf("%c", &x);
    enqueue(x, q, &top, &rear);
    printf_queue_ary(q, top, rear);

    y = dequeue(q, &top, &rear);
    printf("After dequeue\n");
    printf_queue_ary(q, top, rear);
    printf("The character dequeued is %c。\n", y);

    return 0;
}

void printf_queue_ary(char* q, int top, int rear)
{
    int i;
    printf("<---REAR = %d\n", rear);
    for (i = rear - 1; i >= top + 1; i--)
        printf("%c\n", q[i]);
    printf("%c<---TOP = %d\n", q[top], top);
}

void enqueue(char c, char* q, int* top, int* rear) {
    q[*rear] = c; (*rear)++;
}

char dequeue(char* q, int* top, int* rear)
{
    char x;
    x = q[*top]; (*top)++;
    return x;
}