#include<stdio.h>

#define NUMBER (4)

int main(void)
{
    int i, j;
    int Array_1[NUMBER][NUMBER] = { { 1, 2, 3, 4},
                                    { 5, 6, 7, 8},
                                    { 9,10,11,12},
                                    {13,14,15,16} };
    int Array_2[NUMBER][NUMBER] = {};

    printf("Before array:\n");
    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < NUMBER; j++)
            printf("%3d", Array_1[i][j]);
        printf("\n");
    }

    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < NUMBER; j++)
            //Array_2[j][(NUMBER - 1) - i] = Array_1[i][j];
            Array_2[i][j] = Array_1[(NUMBER - 1) - j][i];
    }

    printf("Rotate right 90 deg\n");
    printf("After array:\n");
    for (i = 0; i < NUMBER; i++) {
        for (j = 0; j < NUMBER; j++)
            printf("%3d", Array_2[i][j]);
        printf("\n");
    }


    return 0;
}
