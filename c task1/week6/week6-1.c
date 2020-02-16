#include <stdio.h>
#define NUMBER 3
int main(void)
{
  int i, j;
  int u[NUMBER][NUMBER]={};

  for(i=0; i<NUMBER; i++){
    for(j=0; j<NUMBER; j++){
      printf("input u[%d][%d]: ", i, j);
      scanf("%d", &u[i][j]);
    }
  }
  printf("\n");

  puts("The matrix is");
  for(i=0; i<NUMBER; i++){
    for(j=0; j<NUMBER; j++)
      printf("%4d", u[i][j]);
      printf("\n");
    
  }
  return 0;
}
