#include<stdio.h>

void printf_stack_ary(char* s, int top);
char pop(char* s, int* top);
void push(char c, char* s, int* top);

int main(void) {

    char s[15];
    int top = 0;
    char y;

    s[top] = 'a'; top++;
    s[top] = 'b'; top++;
    s[top] = 'c'; top++;
    s[top] = 'd'; top++;

    push('x', s, &top);
    printf_stack_ary(s, top);
    printf("After pop\n");
    y = pop(s, &top);
    printf_stack_ary(s, top);
    printf("The character popped is %c\n", y);

    return 0;
}

char pop(char* s, int* top)
{
    char x;
    (*top)--;
    x = s[*top];

    return x;
}

void push(char c, char* s, int* top)
{
    s[*top] = c; (*top)++;
}

void printf_stack_ary(char* s, int top)
{
    int i;
    printf("<---TOP=%d\n", top);
    for (i = top - 1; i >= 0; i--)
        printf("%c\n", s[i]);
}