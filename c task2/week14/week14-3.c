#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool seed[5];

struct node {
    struct node* prev;
    int key;
    struct node* next;
};

struct node* member(struct node** table, int key) {
    struct node* clone;
    int mod = key % 5;

    clone = table[mod];
    while (clone != NULL) {
        if (clone->key == key)
            return clone;
        clone = clone->next;
    }
    return NULL;
}

void print_hash(struct node** table) {
    struct node* clone;
    int i;

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

void insert(struct node** table, int key) {
    struct node* top;
    int mod = key % 5;

    top = (struct node*)malloc(sizeof(struct node));
    top->key = key;

    if (seed[mod] == false) {
        top->prev = NULL;
        top->next = NULL;
        table[mod] = top;
        seed[mod] = true;
    }
    else/*(seed[mod] == true)*/ {
        top->next = table[mod];
        table[mod]->prev = top;
        table[mod] = top;
    }
}

int main(void)
{
    struct node* table[5];
    int i, ikey/*insert key*/;

    for (i = 0; i < 5; i++) {
        table[i] = NULL;
        seed[i] = false;
    }

    while (1) {
        printf("Insert Key: "); scanf("%d", &ikey);
        if (ikey < 0)
            break;
        else {
            if (member(table, ikey) == NULL) {
                insert(table, ikey);
                print_hash(table);
            }
            else printf("Error!!\n");
        }
    }

    for (i = 0; i < 5; i++)
        free(table[i]);

    return 0;
}