#include<stdio.h>

void bubblesort(int num[], int n);
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
        bubblesort(a, cnt);
        print_sort(a, cnt);
    }
    return 0;
}

void bubblesort(int num[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (num[j - 1] > num[j]) {
                temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

void print_sort(int num[], int n) {

    int i = 0;
    printf("a = [");
    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
}
