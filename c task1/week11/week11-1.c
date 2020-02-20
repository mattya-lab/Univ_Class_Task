#include <stdio.h>

int main(void)
{
    int a, *b;
    b = &a;

    printf("Input a's value: "); scanf("%d", &a);

    printf("a's value is %d.\n", *b);
    printf("a's address is %p.\n", &b);

    return 0;
}
