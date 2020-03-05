#include<stdio.h>

#define BUFFER_SIZE (255)

int B[BUFFER_SIZE] = {};

void merge(int A[], int left, int mid, int right)
{
    int i = left, j = mid, k = 0, l = 0;

    while (i < mid && j < right) {
        if (A[i] < A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }

    if (i == mid) {
        while (j < right)
            B[k++] = A[j++];
    }

    else {
        while (i < mid)
            B[k++] = A[i++];
    }
    for (l = 0; l < k; l++)
        A[left + l] = B[l];
}

void merge_sort(int A[], int left, int right) {
    /* left = 0, right = number */
    if (left == right || left == right - 1) return;

    int mid = (left + right) / 2;
    /* Recursive Calling */
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);

    merge(A, left, mid, right);
}

int main(void) {
    FILE* fp  /* numbers.dat */;
    int num[BUFFER_SIZE] = {};
    int number = 0;
    int i = 0;

    if ((fp = fopen("numbers.dat", "r")) == NULL) {
        printf("DO NOT OPEN\n");
    }
    else {
        while (fscanf(fp, "%d", &num[number]) != EOF)
            number++;

        printf("-----------------\n");
        for (i = 0; i < number; i++)
            printf("%d ", num[i]);
        printf("\n");
        printf("----------------\n");

        merge_sort(num, 0, number);

        for (i = 0; i < number; i++)
            printf("%d ", num[i]);
        printf("\n");
        printf("-----------------\n");
    }
    return 0;
}
