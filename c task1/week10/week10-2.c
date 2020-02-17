#include <stdio.h>

#define NUMBER 3
#define BUFFER_SIZE 255

int main(void)
{
    char x[NUMBER][BUFFER_SIZE];
    int i, j = 0;

    for (i = 0; i < NUMBER; i++) {
        printf("Input %d index's String sentence: ", i + 1);
        fgets(x[i], BUFFER_SIZE, stdin);
        x[i][strlen(x[i]) - 1] = '\0';
    }

    for (i = 0; i < NUMBER; i++) {
        while (x[i][j] != '\0')
            j++;
        printf("%d index's string sentence is %s。String size is %d\n", i + 1, x[i], j);
        j = 0;
    }

    return 0;
}
