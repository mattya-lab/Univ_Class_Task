#include<stdio.h>
#include<stdlib.h>
#define BUFFER_SIZE 15
int check_heap(int a[], int n);
void insert(int val, int a[], int* n);

int main() {
    int heap[BUFFER_SIZE] = {};
    int i, check, heap_size = 0;

    insert(91, heap, &heap_size);
    insert(63, heap, &heap_size);
    insert(71, heap, &heap_size);
    insert(14, heap, &heap_size);
    insert(1, heap, &heap_size);

    check = check_heap(heap, heap_size);
    if (check == 1) {
        printf("Heap condition is True\n");
    }
    if (check == 0) {
        printf("Heap condition is False\n");
    }

    for (i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    putchar('\n');

    return 0;
}

int check_heap(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if ((2 * i + 1) >= n)
            continue;
        if (a[2 * i + 1] < a[i]) /* Left child < Parent */
            return 0;
        if ((2 * i + 2) >= n)
            return 0;
        if (a[2 * i + 2] < a[i]) /* Right child < Parent */
            return 0;

    }
    return 1;
}

void insert(int val, int a[], int* n)
{
    int i;
    int temp;

    (*n)++;
    a[*n] = val;
    for (i = *n; i > 1; i--) {
        if (a[i / 2] <= a[i]) { /* Parent < Child */
            continue;
        }
        else {
            temp = a[i / 2];
            a[i / 2] = a[i];
            a[i] = temp;
        }
    }
}

