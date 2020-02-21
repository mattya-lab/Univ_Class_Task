#include<stdio.h>
#include <string.h>
#define NUMBER 5
#define BUFFER_SIZE 255
void swap_str(char* sx, char* sy)
{
    char temp[BUFFER_SIZE];

    strcpy(temp, sx);
    strcpy(sx, sy);
    strcpy(sy, temp);
}

int main(void)
{
    char str[NUMBER][BUFFER_SIZE] = {};
    /*  int order[NUMBER]={0, 1, 2, 3, 4};//str[0], str[1], str[2]...*/
    int i, j;
    ;
    for (i = 0; i < NUMBER; i++) {
        printf("Input %d row's string sentence.(Max 255):", i + 1);
        fgets(str[i], 255, stdin);
        str[i][strlen(str[i]) - 1] = '\0';
    }

    for (i = 0; i < NUMBER - 1; i++) { //i = 0 -> 1 -> 2 -> 3 -> 4
        for (j = NUMBER - 1; j > i; j--) { // j = 4 -> 3 -> 2 -> 1 - > 0 
            if (strcmp(str[j - 1], str[j]) > 0) {
                swap_str(str[j - 1], str[j]); //strもswap
            }
        }
    }

    printf("Sort to dictionary order.\n");
    for (i = 0; i < NUMBER; i++) {
        printf("%s\n", str[i]);
    }
    return 0;
}

