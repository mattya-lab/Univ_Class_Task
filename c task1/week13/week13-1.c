#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 255

struct Product
{
    char code[BUFFER_SIZE];
    char name[BUFFER_SIZE];
    int price;
};

int main(void)
{
    struct Product product;
    printf("Input product's code.\n"); scanf("%s", &product.code);
    printf("Input product's name.\n"); scanf("%s", &product.name);
    printf("Input Product's price.\n\n"); scanf("%d", &product.price);

    printf("Product's code: %s\n", product.code);
    printf("Product's name: %s\n", product.name);
    printf("Product's price: %d\n", product.price);

    return 0;
}
