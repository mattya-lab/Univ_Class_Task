#include <stdio.h>
void print_sort(int num[], int l);
void selectionsort(int num[], int n);

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
        selectionsort(a, cnt);
        print_sort(a, cnt);
    }
    return 0;
}
void selectionsort(int num[], int n)
{
    int i, j;
    int min;
    int temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (num[j] < num[min]) {
                min = j;
            }
        }
        temp = num[i];
        num[i] = num[min];
        num[min] = temp;
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
