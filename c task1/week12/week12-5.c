#include<stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define BUFFER_SIZE_2 256

int main(void)
{
    char mes[BUFFER_SIZE] = {};
    char wordsearch[BUFFER_SIZE] = {};
    int mes_len = 0, wordsearch_len = 0, cnt = 0, flag = 0;
    int i = 0, j = 0 /*, loop=0*/;

    printf("Input string sentence(Max %d word): ", BUFFER_SIZE);
    fgets(mes, 1023, stdin); mes[strlen(mes) - 1] = '\0';

    printf("Input the word you want to find.(Max %d words): ", BUFFER_SIZE_2);
    fgets(wordsearch, 255, stdin);
    wordsearch[strlen(wordsearch) - 1] = '\0';
    //Each string sentence's count
    mes_len = strlen(mes);  wordsearch_len = strlen(wordsearch);

    //Start to search.(Can't distinguish from large chracter and small character.:c)
    while (i < mes_len && j < wordsearch_len) {
        if (wordsearch[j + 1] == '\0') {
            cnt = (i - j) + 1; flag = 1; break;
        }

        if (mes[i] == wordsearch[j]) {
            i++; j++;
        }
        else {
            i = (i + 1) - j; j = 0;
        }
    }

    //Judge flag value 0 or 1  
    if (flag == 1) {
        printf("Find the word %s and %d th.\n", wordsearch, cnt);
    }
    else {
        printf("Can't find the word %s.\n", wordsearch);
    }

    return 0;
}

