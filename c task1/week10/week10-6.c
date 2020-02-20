#include<stdio.h>

#define BUFFER_SIZE (256)
#define NUMBER (5)

int longest(const char str[][BUFFER_SIZE])
{
    int i, j, len, key = 0;
    int str_len[NUMBER] = {};

    for (i = 0; i < NUMBER; i++) {
        len = 0;
        while (str[i][len]) {
            len++;
        }
        str_len[i] = len;
    }

    for (i = 0; i < NUMBER; i++) {
        if (str_len[key] < str_len[i]) {
            key = i;
        }
    }
    return key;
}

int main(void)
{
    int i, key;
    char str[NUMBER][BUFFER_SIZE] = {};

    for (i = 0; i < NUMBER; i++) {
        printf("Input %d row's string sentence. (Max %d words): ",
            i + 1, BUFFER_SIZE);
        fgets(str[i], 256, stdin);
        str[i][strlen(str[i]) - 1] = '\0';

    }

    key = longest(str);
    printf("The longest sentence is %d row's %s\n", key + 1, str[key]);
    return 0;
}

