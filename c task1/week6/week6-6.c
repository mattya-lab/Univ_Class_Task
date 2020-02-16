#include<stdio.h>

#define NUMBER_1 (3)
#define NUMBER_2 (5)

int main(void)
{
    int i, j;
    int matrix[NUMBER_1][NUMBER_1] = { {1,2,3},
                                       {4,5,6},
                                       {7,8,9} };
    int rotate[NUMBER_2][NUMBER_2] = {};

    printf("Before array\n");
    for (i = 0; i < NUMBER_1; i++) {
        for (j = 0; j < NUMBER_1; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }

    for (i = 0; i < NUMBER_1; i++) {
        for (j = 0; j < NUMBER_1; j++) {
            rotate[i + j][(2 - i) + j] = matrix[i][j];
            /* rotate[j+i][j+2-i] = matrix[i][j]; */
        }
    }
    printf("Rotate right 45 deg\n");
    printf("After array\n");
    for (i = 0; i < NUMBER_2; i++) {
        for (j = 0; j < NUMBER_2; j++) {
            /*printf("%2d", rotate[i][j]);*/
            if (rotate[i][j] == 0) printf("  ");
            else printf("%2d", rotate[i][j]);
        }
        printf("\n");
    }

    return 0;
}
