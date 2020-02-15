#include<stdio.h>

int main(void)
{
    int i, j, num;

    do {
        printf("Positive odd number of rows: "); scanf("%d", &num);
    } while (num % 2 == 0 || num < 0);

    for (i = 0; i < num; i++) {
        /*(1) Top row and Bottom row*/
        if (i == 0 || i == num - 1) {
            printf("*");
            for (j = 1; j < num - 1; j++)
                printf("-");
            printf("*");
            printf("\n");
        }
        /*(2) Middle row*/
        else if (i == (num - 1) / 2) {
            for (j = 0; j < (num - 1) / 2; j++)
                printf("-");
            printf("*");
            for (j = (num - 1) / 2 + 1; j < num; j++)
                printf("-");
            printf("\n");
        }
        /*(3) Above the middle row*/
        else if (0 < i && i < (num - 1) / 2) {
            for (j = 0; j < i; j++)
                printf("-");
            printf("*");
            for (j = i + 1; j < (num - 1) - i; j++)
                printf("-");
            printf("*");
            for (j = (num - 1) - i; j < (num - 1); j++)
                printf("-");
            printf("\n");
        }
        /*(4) Below the middle row*/
        else {
            for (j = 0; j < (num - 1) - i; j++)
                printf("-");
            printf("*");
            for (j = num - i; j < i; j++)
                printf("-");
            printf("*");
            for (j = i + 1; j < num; j++)
                printf("-");
            printf("\n");
        }
    }
    printf("\n");
    
    return 0;
}
