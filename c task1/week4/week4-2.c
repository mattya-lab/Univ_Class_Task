#include <stdio.h>

int main(void)
{
    int i, num, flag = 0;

    printf("Natural Number? ");  scanf("%d", &num);

    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%d is Prime number!\n", num);
    else
        printf("%d isn't Prime number!\n", num);

     return 0;
}
