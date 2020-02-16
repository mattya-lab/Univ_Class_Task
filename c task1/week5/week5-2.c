#include <stdio.h>

#define BUFFER_SIZE 500

int main(void)
{
    int n, i, v[BUFFER_SIZE];

    do {
        printf("The number of input data is ?(Max %d) ", BUFFER_SIZE); scanf("%d", &n);
    } while (n < 1 || BUFFER_SIZE < n);


    for (i = 0; i < n; i++) {
        printf("%d index's data is: ", i); scanf("%d", &v[i]);
    }
    putchar('\n');


    for (i = n - 1; i >= 0; i--) {
        printf("%d index's content is %d\n", i, v[i]);
    }

    return 0;
} 
