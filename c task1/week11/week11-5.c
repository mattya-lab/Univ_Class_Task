#include<stdio.h>

#define NUMBER (3)

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int array[])
{
    int i, max = 0;
    for (i = 0; i < NUMBER; i++) {
        if (array[max] < array[i])
            max = i;
    }

    swap(&array[0], &array[max]);

    if (array[1] < array[2])
        swap(&array[1], &array[2]);
}

int main(void)
{
    int i;
    int array[NUMBER] = {};

    for (i = 0; i < NUMBER; i++) {
        printf("Input %d index's value.: ", i + 1);
        scanf("%d", &array[i]);
    }

    sort(array);

    for (i = 0; i < NUMBER; i++)
        printf("%2d\n", array[i]);

    return 0;
}