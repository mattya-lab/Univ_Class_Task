#include<stdio.h>

int main(void)
{
    FILE* fp;

    if ((fp = fopen("helloworld.txt", "w")) == NULL)
        printf("\nCan't open this file.\n");
    else {
        fprintf(fp, "Hello world!!\nWhen I woke up this morning, I found many people in my room.\nWhat's up?? : -0");
        fclose(fp);
    }
    return 0;
}