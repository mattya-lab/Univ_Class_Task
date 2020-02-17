#include <stdio.h>
#define NUMBER 512

double ave(int v[], int n)
{
  int i;
  int sum=0;
  double ave;

  for(i=0; i<n; i++){
    sum += v[i];
  }
  ave=sum/n;
  return ave;
}


int main(void)
{
  int i, n;
  int v[NUMBER];

  printf("Input array's size: ");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("v[%d] :", i); scanf("%d", &v[i]);
  }

  printf("Average is %.1lf.\n", ave(v, n));

return 0;
}
