#include <stdio.h>

void cal(int* x, int* y, int n)
{
    switch (n) {
    case 1: (*x) = (*x) + (*y); break;
    case 2: (*x) = (*x) - (*y); break;
    case 3: (*x) = (*x) * (*y); break;
    case 4: (*x) = (*x) / (*y); break;
    }
}

int main(void)
{
    int a = 1, b, n;

    printf("Input a's  value: "); scanf("%d", &a);

    while (1) {
        printf("Input number how to calculate in 4 type\n");
        printf("1: + , 2: - ,3: * , 4: / , 5: Finish : "); scanf("%d", &n);

        if (n < 1 || 5 < n)
            continue;
        else if (n == 5) {
            printf("Finish!\n"); break;
        }
        else {
            switch (n) {
            case 1:printf("a + \n"); scanf("%d", &b); break;
            case 2:printf("a - \n"); scanf("%d", &b); break;
            case 3:printf("a * \n"); scanf("%d", &b); break;
            case 4:printf("a / \n"); scanf("%d", &b); break;
            }

            cal(&a, &b, n);
            printf("The answer to calculation is %d.\n", a);
        }
    }

    return 0;
}