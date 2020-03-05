#include<stdio.h>
#define BUFFER_SIZE (255)

void swap(int* x, int* y) {
    int temp = (*x);
    (*x) = (*y);
    (*y) = temp;
}

int partition(int array[], int left, int right) {
    int i = left, j = right + 1, pivot = left;
    while (i < j) {
        while (array[i] < array[pivot]) i++;
        while (array[pivot] < array[j]) j--;

        if (i < j) swap(&array[i], &array[j]);
    }

    swap(&array[pivot], &array[j]);
    return j;
}

void quick_sort(int array[], int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partition(array, left, right);
        /* Ricursive calling based the pivot value */
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

int main(void) {
    FILE* fp;
    int num[BUFFER_SIZE] = {};
    int number = 0;
    int i, j;

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

        quick_sort(num, 0, number - 1);

        for (i = 1; i <= number; i++)
            printf("%d ", num[i]);
        printf("\n");
        printf("----------------\n");
    }
    return 0;
}
