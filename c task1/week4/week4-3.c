#include <stdio.h>

int main(void)
{
    int i = 2, number = 0;

    while (i < 12)
    {
        number = ++i;
        if (number == 7 || number == 11)
            continue;

        printf("Regular %d:", number);

        while (number >= 1)
        {
            printf("%3d deg　1m", 360 / i);
            number--;
        }
        printf("\n");
    }

    return 0;
}
