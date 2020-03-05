#include<stdio.h>

#define BUFFER_SIZE (255)

void swap(int* x, int* y);
void insert(int val, int a[], int* n);
int deletemin(int a[], int* n);

int main(void)
{
    FILE* fp;
    int num[BUFFER_SIZE] = {};
    int number = 0;
    int heap[BUFFER_SIZE] = {};
    int heap_size = 0;
    int i = 0, j = 0;

    if ((fp = fopen("numbers.dat", "r")) == NULL)
        printf("DO NOT OPEN\n");
    else {
        while (fscanf(fp, "%d", &num[number]) != EOF)
            number++;

        printf("-----------------\n");
        for (i = 0; i < number; i++)
            printf("%d ", num[i]);

        printf("\n");
        printf("----------------\n");

        for (i = 0; i < number; i++)
            insert(num[i], heap, &heap_size);

        for (i = 1; i <= heap_size; i++)
            printf("%d ", heap[i]);

        printf("\n");


        for (i = 1; i <= 10; i++) {
            num[i] = deletemin(heap, &heap_size);
            printf("-----------------\n");
            printf("DELETED: %d\n", num[i]);
            for (j = 1; j <= heap_size; j++) {
                printf("%d ", heap[j]);
            }
            printf("\n");
        }
        for (i = 1; i <= number; i++)
            printf("%d ", num[i]);

        printf("\n");
    }
    return 0;
}

void swap(int* x, int* y) {
    int temp = (*x);
    *x = *y;
    *y = temp;
}
void insert(int val, int a[], int* n)
{
    int i = 0, temp = 0;

    (*n)++;  a[*n] = val;
    for (i = *n; i > 1; i--) {
        if (a[i / 2] <= a[i])
            continue;
        else
            swap(&a[i / 2], &a[i]);
    }
}

int deletemin(int a[], int* n)
{
    int i, temp, del;

    del = a[1];
    a[1] = a[*n];
    (*n)--;

    for (i = 0; 2 * i < (*n); i++) {
        if (a[2 * i] > a[2 * i + 1]) {
            if (a[i] > a[2 * i + 1])
                swap(&a[i], &a[2 * i + 1]);
            else
                continue;
        }
        else if (a[2 * i] < a[2 * i + 1]) {
            if (a[2 * i] < a[i])
                swap(&a[i], &a[2 * i]);
            else
                continue;

        }
        else
            continue;
    }
    return del;
}
