#include <stdio.h>
#define BUFFER_SIZE 255

void arrayPlus(int* a, int* b, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        *(a + i) = *(a + i) + *(b + i);
    }
}

int main(void)
{
    int i, n;
    int x[BUFFER_SIZE], y[BUFFER_SIZE];

    printf("Input number of elements in the vector.(Max %d): ", BUFFER_SIZE - 1);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Input First vector: %d index's element: ", i + 1);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Input Second vector: %d index'a element: ", i + 1);
        scanf("%d", &y[i]);
    }

    printf("The sum of 2 vector: \n");
    printf("(");

    arrayPlus(x, y, n);
    for (i = 0; i < n - 1; i++) {
        printf("%d,", x[i]);
    }
    printf("%d", x[n - 1]);
    printf(")\n");

    return 0;
}