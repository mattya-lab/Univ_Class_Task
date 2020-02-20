#include<stdio.h>
#include <string.h>

#define NUMBER 3
#define BUFFER_SIZE 16

int main(void)
{
    const char *ptr[NUMBER] = { "BKC","NojiHigashi","Kusatsu" };
    char str[NUMBER][BUFFER_SIZE] = { '\0' };
    int a = 0, b = 0, i;

    for (i = 0; i < NUMBER; i++) {
        strcpy(str[i], ptr[i]);
        printf("Copied %d row's string sentence %s\n", i + 1, str[i]);
    }
    a = &str[2][15] - &str[0][0] + 1;
    printf("The area occupied by the string of str is %d.\n", a);

    for (i = 0; i < NUMBER; i++) {
        b += (strlen(ptr[i]) + 1);
    }
    printf("The area occupied by the string of ptr is %d.\n", b);

    return 0;
}

