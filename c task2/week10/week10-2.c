#include<stdio.h>

int check_heap(int a[], int n);

int main(void)
{
    int num[10+1] = { '\0',1,13,24,14,15,71,91,63,80,60 };

    printf("check_heap = %d\n", check_heap(num, 10+1));
    return 0;
}

int check_heap(int a[], int n)
{
    int i;
    int left, right;

    for (i = 0; i < n; i++) {
        left = i * 2 + 1;
        right = i * 2 + 2;

        if (left >= n) {
            continue;
        }
        if (a[left] < a[i]) { /* Left child < Parent */ 
            return 0;
        }
        if (right >= n) {
            continue;
        }
        if (a[right] < a[i]) { /* Right child < Parent */
            return 0;
        }
    }
    return 1;
}
