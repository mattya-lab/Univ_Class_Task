#include <stdio.h>

#define NUMBER 256

int main(void)
{
    char x[NUMBER];
    int i = 0;

    printf("Input string sentence (Max %d): ", NUMBER); fgets(x, 256, stdin);
    x[strlen(x) - 1] = '\0';

    while (x[i] != '\0') { i++; }

    printf("String sentence is %s. String size is %d\n", x, i);

    return 0;
}