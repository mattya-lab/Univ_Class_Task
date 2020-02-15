#include<stdio.h>

#define BUFFER_SIZE 500

int main(void)
{
    int i, num, sum; /* sum is inner product sum */
    int x[BUFFER_SIZE], y[BUFFER_SIZE];

    printf("Is the number of the element in the vectore ?(Max %d): ", BUFFER_SIZE);
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Vector x: %d index's element: ", i + 1); scanf("%d", &x[i]);
    }

    for (i = 0; i < num; i++) {
        printf("Vector y: %d index's element: ", i + 1); scanf("%d", &y[i]);
    }

    for (i = 0; i < num; i++)
        sum += x[i] * y[i];

    printf("Vector X * Vector Y = %d\n", sum);
  return 0;
}
