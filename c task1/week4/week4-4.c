#include <stdio.h>

int main(void)
{
    int i, j, k, n;
    printf("Positive integer: "); scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (k = 1; k <= n - i; k++) putchar(' ');
        for (j = 1; j <= (i * 2) - 1; j++) putchar('*');
        printf("\n");
    }

    return 0;
}
