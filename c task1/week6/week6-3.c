#include <stdio.h>

#define NUMBER 10
#define NUMBER2 2

int main(void)
{
  int i,j;
  int score_rank[NUMBER][NUMBER2]={{67,0},{48,0},{56,0},{97,0},{30,0},
			                       {88,0},{76,0},{55,0},{66,0},{78,0}};
  int rank=1;


  puts("Score rank");
  for (i = 100; i >= 0; i--) {
      for (j = 0; j < NUMBER; j++) {
          if (score_rank[j][0] == i) {
              score_rank[j][1] = rank;
              rank++;
              break;
          }
      }
  }


  for(i=0; i<NUMBER; i++){
    for(j=0; j<NUMBER2; j++)
      printf("%3d", score_rank[i][j]);
    putchar('\n');
  }

  return 0;
}
