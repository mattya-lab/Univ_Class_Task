#include<stdio.h>
#include <string.h>

#define NUMBER 3
#define BUFFER_SIZE 16

int main(void)
{
    char str[NUMBER][BUFFER_SIZE] = { "BKC","NojiHigashi","Kusatsu" };
    char* ptr[NUMBER][BUFFER_SIZE] = {};
    int i, j;

    for (i = 0; i < NUMBER; i++) {
        printf("Input %d row's string sentence.(Max 15): ", i + 1);
        gets(str[i]);
        //fgets(str[i], 15, stdin);
        //str[i][strlen(str[i]) - 1] = '\0';

        printf("%s Copied to %d row.\n", str[i], i + 1);
    }

    printf("Array str's content is \n");
    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < BUFFER_SIZE; j++) {
            ptr[i][j] = &str[i][j];
        }
    }

    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < BUFFER_SIZE; j++) {
            if (*ptr[i][j] == '\0')
                putchar('*');
            else
                putchar(*ptr[i][j]);
        }
    }
    printf("\n");
    return 0;
}

