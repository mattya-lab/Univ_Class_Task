#include<stdio.h>
#define BUFFER_SIZE 256
#define NUMBER 3

// Prototype declartion
int cnt_(char x[]);

int main(void)
{
    char x[NUMBER][BUFFER_SIZE];
    int n = 0, i = 0;

    for (i = 0; i < NUMBER - 1; i++) {
        printf("Input %d index's string sentence (Max 255 words): ", i + 1);
        fgets(x[i], 256, stdin);
        x[i][strlen(x[i]) - 1] = '\0';
    }

    for (i = 0; i < NUMBER - 1; i++) {
        printf("%d index's string sentence is %s.\n", i + 1, x[i]);
    }

    i = 0;

    while (i != cnt(x[0])) {
        x[NUMBER - 1][i] = x[0][i];
        i++;
    }

    while (x[1][n]) {
        x[NUMBER - 1][i + n] = x[1][n];
        n++;
    }

    x[2][n + i] = '\0';

    printf("String sentence combined is %s.\n", x[2]);
    return 0;
}

int cnt(char x[])
{
    int i = 0;
    while (x[i] != '\0')
        i++;
    return i;
}
