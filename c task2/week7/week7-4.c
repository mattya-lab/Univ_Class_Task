#include<stdio.h>

void printf_queue_ary(char* q, int top, int rear);
void enqueue(char c, char* q, int* top, int* rear);
char dequeue(char* q, int* top, int* rear);

int main(void) {
    char q[15];
    int top = 0, rear = 0;
    char x, y;

    while (1) {
        printf("Input a character(0: Exit, 1: Dequeue, Other: Enqueue):");
        scanf("%c", &x); getchar();
        if (x == '0') {
            printf("Exit\n");
            break;
        }
        else if (x == '1') {
            if (rear == 0) { printf("Empty\n"); }
            else {
                y = dequeue(q, &top, &rear); printf_queue_ary(q, top, rear);
                printf("dequeue= %c, top = %d\n", y, top - 1);
            }
        }
        else {
            enqueue(x, q, &top, &rear); printf_queue_ary(q, top, rear);
        }
    }
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