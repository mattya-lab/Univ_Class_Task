#include<stdio.h>/* Hash */
#include<stdlib.h>

struct node {
    int key;
    struct node* next;
};

struct node* member(struct node** table, int key)
{
    struct node* clone;
    int  mod = key % 5;

    clone = table[mod];
    while (clone != NULL) {
        if (clone->key == key)
            return clone;
        clone = clone->next;
    }
    return NULL;
}

int main(void)
{
    int x[10] = { 18, 9, 22, 4, 21, 12, 15, 31, 7, 25 }, y = 5, skey;
    struct node* table[5], * top, * t = NULL;
    int i = 0, mod;

    for (i = 0; i < 5; i++)
        table[i] = NULL;

    for (i = 0; i < 10; i++) {
        mod = x[i] % y;
        top = (struct node*)malloc(sizeof(struct node));
        top->key = x[i];
        top->next = table[mod];
        table[mod] = top;
    }

    printf("serch member: "); scanf("%d", &skey);

    if (member(table, skey) != NULL)
        printf("Exist Key\n");
    else
        printf("Not Exists Key\n");

    for (i = 0; i < 5; i++)
        free(table[i]);

    return 0;
}