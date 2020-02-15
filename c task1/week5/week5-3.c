#include <stdio.h>

#define NUMBER 5

int main(void)
{
    int n, i, v[NUMBER] = {};
    int max = v[0], index = 0;

    for (i = 0; i < NUMBER; i++) {
        printf("%d index's data: ", i); scanf("%d", &v[i]);
    }
    putchar('\n');

    for (i = 1; i < NUMBER; i++) {
        if (max < v[i]) {
            max = v[i];
            index = i;
        }
    }
    printf("The largest element is %d, and its index is %d\n", max, index);
   
    return 0;
}
