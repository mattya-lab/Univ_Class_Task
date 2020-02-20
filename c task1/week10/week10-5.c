#include<stdio.h>

#define BUFFER_SIZE (256)

int main(void)
{
    int i, count = 0;

    char in_str[BUFFER_SIZE] = {}, out_str[BUFFER_SIZE] = {};
    printf("Input string sentence (Max %d words): ", BUFFER_SIZE);
    fgets(in_str, 256, stdin);
    in_str[strlen(in_str) - 1] = '\0';

    while (in_str[count])
        count++;

    for (i = 0; i < count; i++)
        out_str[i] = in_str[(count - 1) - i];
    out_str[count + 1] = '\0';

    printf("%s reverse string sentence %s.\n", in_str, out_str);

    return 0;
}