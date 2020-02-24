#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE (255)
#define th_TH_SIZE (2)

int main(void) {
    char word[BUFFER_SIZE], word_copy[BUFFER_SIZE] = {};
    int i = 0, j = 0, th_TH_cnt = 0, total_len = 0;

    printf("Input English string sentence.\n");
    while (1) {
        if (scanf("%c", &word[i]) == EOF)
            break;
        else {
            /* '\n' */
            if (word[i] == '\n') {
                printf("%s\n", word_copy);
                i = 0;
            }
            /* others */
            else {
                /*th or TH*/
                if (word[i - 1] == 'h' || word[i - 1] == 'H') {
                    if (word[i - 2] == 't' || word[i - 2] == 'T') {
                        word_copy[i - 2] = '+';
                        word_copy[i - 1] = '+';
                        th_TH_cnt++;;
                    }
                }
                word_copy[i] = word[i];
                i++;
                total_len++;
            }
        }
    }

    printf("\nWord count number: %d\n", total_len);
    printf("Appearance number th or TH: %d\n", th_TH_cnt);
    return 0;
}
