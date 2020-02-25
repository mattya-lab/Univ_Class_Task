#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 255

typedef struct {
    char code[BUFFER_SIZE];
    char name[BUFFER_SIZE];
    int price;
}gift;

int main(void)
{
    int i, n;
    FILE* fp1, * fp2;
    char x[BUFFER_SIZE], y[BUFFER_SIZE];
    char code[BUFFER_SIZE], name[BUFFER_SIZE];
    int price;
    gift* gifts[BUFFER_SIZE];

    printf("Input data's size: "); scanf("%d", &n);
    printf("Choose the file inputted: "); scanf("%s", x);

    if ((fp1 = fopen(x, "rb")) == NULL) {
        printf("Can't open this file.\n");
    }
    else {
        for (i = 0; i < n; i++) {
            gifts[i] = (gift*)malloc(sizeof(gift) * (n + 1));
        }
        printf("Choose the file will output: "); scanf("%s", y);
        fp2 = fopen(y, "wb");

        while (fscanf(fp1, "%s %s %d", code, name, &price) != EOF) {
            strcpy(gifts[i]->code, code);
            strcpy(gifts[i]->name, name);
            gifts[i]->price = price;

            fprintf(fp2, "code: %s\n", gifts[i]->code);
            fprintf(fp2, "name: %s\n", gifts[i]->name);
            fprintf(fp2, "price: %d\n\n", gifts[i]->price);

            i++;
        }
        for (i = 0; i < n; i++) {
            free(gifts[i]);
        }
        fclose(fp1);
        fclose(fp2);
        printf("Output the file exchanged to display format.\n");
    }
    return 0;
}
