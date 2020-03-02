#include<stdio.h>

void printf_queue_ary(char* q, int top, int rear) {
    int i;
    printf("<---REAR = %d\n", rear);
    for (i = rear - 1; i >= top + 1; i--)
        printf("%c\n", q[i]);
    printf("%c<---TOP = %d\n", q[top], top);
}

void enqueue(char c, char* q, int* top, int* rear) {
    q[*rear] = c; (*rear)++;
}

char dequeue(char* q, int* top, int* rear) {
    char y;
    y = q[*top]; (*top)++; return y;
}

int main(void)
{
    char queue[15], queue_2[15], x, y;
    int top = 0, rear = 0, top_2 = 0, rear_2 = 0, flag = 0, i = 0;

    while (1) {
        printf("Input a character(0: Exit, 1: Dequeue, Other: Enqueue): ");
        scanf("%c", &x); getchar();

        if (x == '0') { printf("Exit\n");  break; }
        else if (x == '1') {
            if (top == rear)
                printf("Empty\n");
            else {
                y = dequeue(queue, &top, &rear);
                printf_queue_ary(queue, top, rear);
                printf("dequeue= %c, top = %d\n", y, top - 1);
            }
        }
        else {
            /* State A -> State B */
            for (i = top; i < rear; i++) {
                if (x == queue[i]) {
                    flag = 1;
                    continue;
                }
                else
                    enqueue(queue[i], queue_2, &top, &rear_2);

            }

            printf("Check queue_2\n");
            for (i = rear_2 - 1; i >= top_2; i--)
                printf("%c\n", queue_2[i]);

            /* State B -> State C*/
            rear = top;
            for (i = top_2; i < rear_2; i++) {
                queue[rear] = queue_2[i]; rear++;
            }

            if (flag == 0)
                enqueue(x, queue, &top, &rear);

            printf("Check queue\n");
            printf_queue_ary(queue, top, rear);

            /* initialize */
            flag = 0;  rear_2 = 0;
        }

    }
    return 0;
}