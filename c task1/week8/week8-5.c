#include<stdio.h>
#define NUMBER (2)

void foo(int a[][NUMBER+1], int b[][NUMBER], int c[NUMBER][NUMBER])
{
    int i, j, k;
     for(i = 0; i < NUMBER; i++){
        for(j = 0; j < NUMBER; j++){
           for(k = 0; k < NUMBER+1; k++)
	           c[i][j] += a[i][k] * b[k][j];
        }
     }
}

void mat_print(int x[][NUMBER])
{
     int i, j;
     for(i = 0; i < NUMBER; i++){
         for(j = 0; j < NUMBER; j++)
            printf("%2d ", x[i][j]);
         printf("\n");
     } 
}

int main(void)
{
     int A[NUMBER][NUMBER+1] = {{1,2,3},
			                    {4,5,6}};
     int B[NUMBER+1][NUMBER] = {{2,3},
			                    {4,5},
			                    {6,7}};
     int C[NUMBER][NUMBER] = {};

     foo(A, B, C);
     mat_print(C);
     return 0;
}
