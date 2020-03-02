#include<stdio.h>

void printf_stack_ary(char* s, int top)
{
    int i;
    printf("<---TOP=%d\n", top);
    for (i = top - 1; i >= 0; i--) {
        printf("%c\n", s[i]);
    }
}

int main(void)
{
    char s[15];    // stack's array // 
    int top = 0;   // stack pointer //

    s[top] = 'a'; top++;
    s[top] = 'b'; top++;
    s[top] = 'c'; top++;
    s[top] = 'd'; top++;

    printf_stack_ary(s, top);

    return 0;
}
