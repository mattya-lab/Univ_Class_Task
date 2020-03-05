#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* parent, * left, * right;
};

struct node* new_node(int key)
{
    struct node* p;

    p = (struct node*)malloc(sizeof(struct node));
    p->key = key;
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL;

    return p;
}
void print_tree(struct node *node);

void free_tree(struct node* node) {
    if (node != NULL) {
        /* Recursive function */
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int insert(int key, struct node* root) {
    while (root->key != key && root->key != 0) {
        /* If child is smaller than parent */
        if (root->key > key) root = root->left;
        /* If child is bigger than parent */
        else /*if(root->key < key)*/ root = root->right;
    }

    if (root->key != key) {
        root->key = key; root->left = new_node(0); root->right = new_node(0);
        return 1;
    }
    else  return 0;
}

int main() {
    int key; struct node* root = new_node(0);
    for (;;) {
        printf("Input the key to insert: "); scanf("%d", &key);
        if (key == 0) {}
        else if (key > 0) {
            if (insert(key, root) == 1) print_tree(root);
            else {
                printf("The key has already existed.It's ERROR.\n"); print_tree(root);
            }
        }
        else {
            printf("Exit because a non-positive number was inputted.\n"); free_tree(root);
            return 0;
        }
    }
}


