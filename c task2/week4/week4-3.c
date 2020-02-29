#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct word_pair {
    char longer_word[10];
    char shorter_word[10];
    char combined_word[20];
    int longer_word_length;
    int shorter_word_length;
}word_pair_t;

word_pair_t create_word_pair(char* a, char* b);

int main(void) {
    // Define a structure to store the output data 
    word_pair_t pri;

    char str1[10], str2[10];

    printf("Input string sentence a: ");  scanf("%s", str1);
    printf("Input string sentence b: ");  scanf("%s", str2);

    pri = create_word_pair(str1, str2);

    // Result of string sentence's judgement
    printf("Longer string sentence: %s\n", pri.longer_word);
    printf("Longer string sentence length: %d\n", pri.longer_word_length);
    printf("Shorter string sentence: %s\n", pri.shorter_word);
    printf("Shorter string sentence length: %d\n", pri.shorter_word_length);
    printf("Combined string sentence: %s\n", pri.combined_word);

    return 0;
}

word_pair_t create_word_pair(char* a, char* b)
{
    word_pair_t data;

    // Compare a's length and b's length
    if (strlen(a) > strlen(b)) {      // a > b
        strcpy(data.longer_word, a);
        strcpy(data.shorter_word, b);
    }
    else if (strlen(a) < strlen(b)) { // b > a
        strcpy(data.longer_word, b);
        strcpy(data.shorter_word, a);
    }
    else {//( strlen(a) == strlen(b) )  // a = b
        if (strcmp(a, b) > 0) {         // a is first come in dictionary order
            strcpy(data.longer_word, a);
            strcpy(data.shorter_word, b);
        }
        else if (strcmp(a, b) < 0) {    // b is first come in dictionary order
            strcpy(data.longer_word, b);
            strcpy(data.shorter_word, a);
        }
        else if (strcmp(a, b) == 0) {
            printf("Two string sentence inputted are the same.\n");
            strcpy(data.longer_word, a);
            data.shorter_word[0] = '\0';
        }
    }
    data.longer_word_length = strlen(data.longer_word);
    data.shorter_word_length = strlen(data.shorter_word);

    strcpy(data.combined_word, data.longer_word);
    data.combined_word[data.longer_word_length] = ' ';//'\0'→' '
    data.combined_word[data.longer_word_length + 1] = '\0';
    strcat(data.combined_word, data.shorter_word);

    return data;
}