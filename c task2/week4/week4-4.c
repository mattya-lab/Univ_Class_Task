#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE (255)
#define NUMBER 2

int main(void)
{
    char word[BUFFER_SIZE];
    char word_atoi[NUMBER][BUFFER_SIZE], sisoku[BUFFER_SIZE];
    int x = 0, y = 0, z = 0;
    int word_len = 0, cur_index = 0, i = 0, j = 0, k = 0, flag = 0;

    printf("Input a numerical formula: "); scanf("%s", word);

    /* String sentence's Word length */
    while (word[word_len] != '\0')
        word_len++;

    /* Split to x, y, arithmetic operator  */
    for (i = 0; i <= word_len; i++) {
        if ('0' <= word[i] && word[i] <= '9') {
            word_atoi[j][cur_index] = word[i];
            cur_index++;
        }
        else {
            sisoku[k] = word[i];
            j++; k++;
            cur_index = 0;
        }
    }

    /*char type to int type ( atoi function )*/
    x = atoi(word_atoi[0]); y = atoi(word_atoi[1]);

    /* 4 type of calculation */
    switch ( sisoku[0] ) {
    case '+': z = x + y; break;
    case '-': z = x - y; break;
    case '*': z = x * y; break;
    case '/': z = x / y; break;
    default: flag = 1; break;
    }

    if (flag == 0) {
        printf("value 1: %d\n", x);
        printf("Arithmetic operator: %s\n", sisoku);
        printf("Value 2: %d\n", y);
        printf("Calculation result: %d\n", z);
    }
    else printf("ERROR\n");

    return 0;
}