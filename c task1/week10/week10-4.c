#include <stdio.h>
#define BUFFER_SIZE 255
void cnt_char(char x[], int cnt[]);
void x_toupper(char x[]);

int main(void)
{
    char x[BUFFER_SIZE];
    int cnt[BUFFER_SIZE] = { 0 };
    int i;


    printf("Input String sentence(max %d):", BUFFER_SIZE - 1);
    fgets(x, 256, stdin);
    x[strlen(x) - 1] = '\0';

    x_toupper(x);
    cnt_char(x, cnt);

    for (i = 'A'; i <= 'Z'; i++)
        printf("%c: There is %d character\n", i, cnt[i]);

    return 0;
}

void x_toupper(char x[])/* Capitalization */
{
    int i = 0;

    while (x[i])
    {
        x[i] = toupper(x[i]); i++;
    }
}

void cnt_char(char x[], int cnt[])
{
    int i = 0;
    while (x[i])
    {
        if ('A' <= x[i] && x[i] <= 'Z')/*A to Z*/
            //printf("%d", x[i]);
            cnt[x[i]]++;
        i++;
    }
}
