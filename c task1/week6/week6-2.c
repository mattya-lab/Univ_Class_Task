#include <stdio.h>

#define NUMBER_X 2
#define NUMBER_Y 3
#define NUMBER_Z 4

int main(void)
{
  int i, j, k;
  int matrixA[NUMBER_X][NUMBER_Y]={{2, 4, 8},
		                           {7, 3, 3}};

  int matrixB[NUMBER_Y][NUMBER_Z]={{4, 5, 2, 7},
		                           {5, 6, 2, 8},
		                           {1, 2, 3, 6}};

  int matrixC[NUMBER_X][NUMBER_Z] = {};

  for(i=0; i < NUMBER_X; i++){ 
    for(j=0; j < NUMBER_Z; j++){;
      for(k=0; k < NUMBER_Y; k++){
	matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  puts("Array A = ");
  for(i=0; i<NUMBER_X; i++){
    for(j=0; j<NUMBER_Y; j++)
      printf("%2d", matrixA[i][j]);
    putchar('\n');
  }

  puts("Array B = ");
  for(i=0; i<NUMBER_Y; i++){
    for(j=0; j<NUMBER_Z; j++)
      printf("%2d", matrixB[i][j]);
    putchar('\n');
  }

  puts("Array A * B = ");
  for(i=0; i<NUMBER_X; i++){
    for(j=0; j<NUMBER_Z; j++)
      printf("%3d", matrixC[i][j]);
    putchar('\n');
  }

  return 0;
}
