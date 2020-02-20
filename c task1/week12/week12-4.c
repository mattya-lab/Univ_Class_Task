#include<stdio.h>
#include <string.h>

#define NUMBER 5
#define BUFFER_SIZE_1 256
#define BUFFER_SIZE_2 1280

int main(void)
{
    char str[NUMBER][BUFFER_SIZE_1] = {};
    char all[BUFFER_SIZE_2] = {};
    int i, j;

    for (i = 0; i < NUMBER; i++) {
        printf("Input %d row's string sentence.(Max 256):", i + 1);
        fgets(str[i], 256, stdin);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    for (i = 0; i < NUMBER; i++) {
        j = strlen(str[i]);
        printf("%d row's string sentence is %s, and its len is %d.\n", i + 1, str[i], j);

        if (strcmp(str[0], str[i]) > 0)
            strcpy(str[0], str[i]);
        strcat(all, str[i]);
    }
    printf("Earliest in dictionary order is %s.\n", str[0]);
    printf("All string sentence combined is %s.\n", all);

    return 0;
}