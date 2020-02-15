#include <stdio.h>

int main(void)
{
    int i;
    int v[10] = { 10, 5, 25, -10, 7, 0, 52, 27, -8, 1 };

    for (i = 10 - 1; i >= 0; i--)
        printf("%d index's content is %d\n", i, v[i]);

    return 0;
} 
