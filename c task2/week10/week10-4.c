#include<stdio.h>

#define BUFFER_SIZE 15

int check_heap(int a[], int n);
void insert(int val, int a[], int* n);
int deletemin(int a[], int* n);

int main(void) {

    int heap[BUFFER_SIZE];
    int i, j, k;
    int check = 0;
    int heap_size = 0;
    int cnt = 10;

    insert(91, heap, &heap_size); insert(63, heap, &heap_size); insert(71, heap, &heap_size);
    insert(14, heap, &heap_size); insert(60, heap, &heap_size); insert(1, heap, &heap_size);
    insert(24, heap, &heap_size); insert(13, heap, &heap_size); insert(80, heap, &heap_size);
    insert(15, heap, &heap_size);

    for (i = 1; i <= heap_size; i++)
        printf("%d ", heap[i]);
    putchar('\n');

    cnt = heap_size;
    for (j = 1; j <= cnt; j++) {
        printf("DELETE Value: %d\n", deletemin(heap, &heap_size));

        for (k = 1; k <= heap_size; k++)
            printf("%d ", heap[k]);

        check = check_heap(heap, heap_size);
        if (check == 1) printf("The heap condition is true.\n");
        else/*(check== 0)*/printf("The heap condition is false\n");

        putchar('\n');
    }

    return 0;
}

void insert(int val, int a[], int* n) {
    int i, temp;
    (*n)++; a[*n] = val;
    for (i = *n; i > 1; i--) {
        if (a[i / 2] <= a[i]) continue;
        else { temp = a[i / 2]; a[i / 2] = a[i]; a[i] = temp; }
    }
}

int check_heap(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] <= a[2 * i + 1] && a[i] <= a[2 * i + 2]) return 1;
        else return 0;
    }
}

int deletemin(int a[], int* n) {
    int i, temp, x;

    x = a[1];
    a[1] = a[*n];
    (*n)--;

    for (i = 1; 2 * i < (*n); i++) {
        if (a[2 * i] > a[2 * i + 1]) {  /* Left child > Right child*/
            if (a[i] > a[2 * i + 1]) {  /* Swap each values if Parent value is bigger than left child values */
                temp = a[i]; a[i] = a[2 * i + 1]; a[2 * i + 1] = temp;
            }
            else {   /* otherwise */
                continue;
            }
        }
        else if (a[2 * i] < a[2 * i + 1]) {  /* Left child < Right child */
            if (a[2 * i] < a[i]) {           /* Swap each values if Parent value is bigger than right child values */
                temp = a[i]; a[i] = a[2 * i]; a[2 * i] = temp;
            }
            else {    /* otherwise */
                continue;
            }
        }
    }
    return x;
}