#include <stdio.h>

#define NUMBER 500

int main(void)
{
    int n, i;
    int v[NUMBER];
    double sum = 0;
    double average = 0;

    while (1) {
        printf("Is the number of elements in the vector ?(Max %d) ", NUMBER);
        scanf("%d", &n);
        if (1 <= n && n <= NUMBER)
            break;
        printf("Please reduce the number of elements to 500 or less\n", NUMBER);
    }

    for (i = 0; i < n; i++) {
        printf("%d index's element:", i + 1);
        scanf("%d", &v[i]);
        sum += v[i];
    }
    putchar('\n');

    average = (sum) / n;

    printf("The deviation vector is (");
    for (i = 0; i < n - 1; i++) {
        printf("%.1lf,", v[i] - average);
    }
    printf("%.1lf", v[n - 1] - average);
    printf(")\n");
 return 0;
} 
