#include<stdio.h>

void swap(int* x, int* y);

int main()
{
    int x, y;

    printf("Input 2 integer value: ");  scanf("%d %d", &x, &y);
    printf("x's value is %d, y's value is %d.\n", x, y);
    swap(&x, &y);
    printf("After call swap(), x's value is %d, y's value is %d.\n", x, y);
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
