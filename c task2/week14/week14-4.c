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
        if (clone->key == key) return clone;
        clone = clone->next;
    }
    return NULL;
}

void print_hash(struct node** table) {
    int i;
    struct node* clone;

    for (i = 0; i < 5; i++) {
        clone = table[i];
        printf("%d ", i);
        while (clone != NULL) {
            printf("%2d ", clone->key);
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
        top->prev = NULL; top->next = NULL;
        table[mod] = top;
        seed[mod] = true;
    }
    else/*(seed[mod] == true)*/ {
        top->prev = NULL;
        top->next = table[mod];
        table[mod]->prev = top;
        table[mod] = top;
    }
}

void del(struct node** table, int key) {
    struct node* clone;
    int mod = key % 5;

    clone = table[mod];
    while (clone != NULL) {
        if (clone->key == key) {
            if (clone->prev == NULL && clone->next == NULL) {
                table[mod] = NULL;
                seed[mod] = false;
            }
            else if (clone->prev == NULL) {
                clone->next->prev = NULL;
                table[mod] = clone->next;
                clone->next = NULL;
            }
            else if (clone->next == NULL) {
                clone->prev->next = NULL;
                clone->prev = NULL;
            }
            else {
                clone->prev->next = clone->next;
                clone->next->prev = clone->prev;
            }
            free(clone);
            break;
        }
        clone = clone->next;
    }
}

int main(void) {
    int x[10] = { 18, 9, 22, 4, 21, 12, 15, 31, 7, 25 }, y = 5, i;
    struct node* table[5];
    int dkey/*delete key*/;

    for (i = 0; i < 5; i++) {
        table[i] = NULL;
        seed[i] = false;
    }

    for (i = 0; i < 10; i++)
        insert(table, x[i]);

    print_hash(table);

    while (1) {
        printf("Delete Key: "); scanf("%d", &dkey);

        if (dkey < 0)
            break;
        else {
            if (member(table, dkey) != NULL) {
                del(table, dkey);
                print_hash(table);
            }
            else/*(member(table, dkey) == NULL)*/
                printf("Error\n");
        }
    }

    for (i = 0; i < 5; i++)
        free(table[i]);

    return 0;
}