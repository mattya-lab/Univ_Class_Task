#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


#define NUMBER 4
#define BUFFER_SIZE 255
#define FIVE_BIT 31

typedef struct {
    char code[BUFFER_SIZE];
    char name[BUFFER_SIZE];
    int price;
} gift_t;

int main(void)
{
    int i = 0, j = 0;
    char code[BUFFER_SIZE], name[BUFFER_SIZE];
    int price;

    FILE* fp;
    gift_t gift[BUFFER_SIZE] = {};

    if ((fp = fopen("gifts.dat", "r")) == NULL)
        printf("Can't open this file.\n");
    else {
        while (fscanf(fp, "%s %s %d", code, name, &price) != EOF) {
            strcpy(gift[i].code, code);
            strcpy(gift[i].name, name);
            gift[i].price = price;

            for (j = 0; j < FIVE_BIT; j++) {
                gift[i].code[j] = toupper(gift[i].code[j]);
                gift[i].name[j] = toupper(gift[i].name[j]);
            }
            printf("code: %s\n", gift[i].code);
            printf("name: %s\n", gift[i].name);
            printf("price: %d\n\n", gift[i].price);
            i++;
        }

        fclose(fp);

    }
    return 0;
}
