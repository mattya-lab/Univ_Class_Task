#include<stdio.h>

void insertionsort(int num[], int n);
void print_sort(int num[], int n);

int main(void)
{
    FILE* fp;
    int a[10];
    int cnt = 0;

    if ((fp = fopen("numbers.dat", "r")) == NULL) {  /* Read the file */
        printf("Can't open the file.\n");
    }
    else {
        while (fscanf(fp, "%d", &a[cnt]) != EOF) {
            cnt++;
        }
        print_sort(a, cnt);
        insertionsort(a, cnt);
        print_sort(a, cnt);
    }
    return 0;
}

void insertionsort(int num[], int n)
{
    int i, hole, value;

    for (i = 1; i < n; i++) {
        value = num[i];
        hole = i;
        while (hole > 0 && num[hole - 1] > value) {
            num[hole] = num[hole - 1];
            hole = hole - 1;
        }
        num[hole] = value;
    }
}

void print_sort(int num[], int n)
{
    int i = 0;
    printf("a = [");
    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}