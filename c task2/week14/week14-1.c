#include<stdio.h>/* Hash */
#include<stdlib.h>

struct node {
    int key;
    struct node* next;
};

void print_hash(struct node** table) {
    int i;
    struct node* clone;
    for (i = 0; i < 5; i++) {
        clone = table[i];
        printf("%d ", i);
        while (clone != NULL) {
            printf("%d ", clone->key);
            clone = clone->next;
        }
        printf("\n");
    }
}

int main(void) {
    int x[10] = { 18, 9, 22, 4, 21, 12, 15, 31, 7, 25 }, y = 5;
    struct node* table[5], * top;
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

    print_hash(table);
    return 0;
}