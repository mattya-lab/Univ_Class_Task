#include<stdio.h>

#define NUMBER (3)
#define BUFFER_SIZE (15)

void matrix_product(int x[][NUMBER], int y[][NUMBER], int z[][NUMBER])
{
    int i, j, k;

    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < NUMBER; j++)
            z[i][j] = 0;
    }

    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < NUMBER; j++) {
            for (k = 0; k < NUMBER; k++)
                z[i][j] += x[i][k] * y[k][j];
        }
    }
}

void matrix_print(int x[][NUMBER])
{
    int i, j;
    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < NUMBER; j++)
            printf("%3d ", x[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int A[NUMBER][NUMBER] = { {1,0,-1},
                              {1,2,1},
                              {2,2,3} };
    int B[NUMBER][NUMBER] = {};
    int C[NUMBER][NUMBER] = {};
    int D[NUMBER][NUMBER] = {};
    int h, i, j, n;

    do {
        printf("Input n value. (Max %d): ", BUFFER_SIZE); scanf("%d", &n);
        if (15 <= n)
            printf("Please reduce n to %d or less\n", BUFFER_SIZE);
    } while (n < 1 || 15 < n);

    for (h = 1; h < n; h++) {
        if (h == 1) {
            matrix_product(A, A, B);
        }
        else if (h % 2 == 0) { /* Even nuber */
            matrix_product(B, A, C);
        }
        else {                 /* Odd number */
            matrix_product(C, A, B);
        }
    }

    if (n == 1) {
        for (i = 0; i < NUMBER; i++) {
            for (j = 0; j < NUMBER; j++)
                D[i][j] = A[i][j];
        }
    }
    else if (n % 2 == 0) {
        for (i = 0; i < NUMBER; i++) {
            for (j = 0; j < NUMBER; j++)
                D[i][j] = B[i][j];
        }
    }
    else {
        for (i = 0; i < NUMBER; i++) {
            for (j = 0; j < NUMBER; j++)
                D[i][j] = C[i][j];
        }
    }
    matrix_print(D);

    return 0;
}
