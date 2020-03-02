#include<stdio.h>

void printf_queue_ary(char *q,int top,int rear);

int main(void)
{
    char q[15] = {};
    int top = 3;
    int rear = top;

    q[rear] = 'a'; rear++;
    q[rear] = 'b'; rear++;
    q[rear] = 'c'; rear++;
    q[rear] = 'd'; rear++;

    printf_queue_ary(q,top,rear);

    return 0;
}

void printf_queue_ary(char *q,int top,int rear)
{
    int i;

    printf("%c<---TOP=%d\n", q[top], top);
    for(i = top + 1; i <= rear - 1; i++)  
         printf("%c\n", q[i]);
    printf("<---REAR=%d\n",rear);
}
