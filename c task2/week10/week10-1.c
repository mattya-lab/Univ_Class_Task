#include <stdio.h>

int main(void) {

    int num[11] = { '\0',1,13,24,14,15,71,91,63,80,60 };
    int i;

    for (i = 1; i <= 10; i++)
        printf("%d ", num[i]);

    printf("\n");
    return 0;
}