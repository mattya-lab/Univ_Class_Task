#include <stdio.h>

typedef struct gift
{
    char code[255];
    char name[255];
    int price;
} gift_t;


int main(void)
{

    gift_t gift = { "JZK-30","Jizake_tsumeawase",4500 };

    printf("code: %s\n", gift.code);
    printf("name: %s\n", gift.name);
    printf("price: %d\n", gift.price);

    return 0;
}