#include <stdio.h>


double multFloat(double a, double b){ return a * b; }

int main(void)
{
  double x, y;

  while(1){
    printf("First value: ");  scanf("%lf", &x);
    printf("Second value: "); scanf("%lf", &y);
    if(x==0 && y==0)
      break;
    printf("%.2lf\n", multFloat(x, y));
  }

  return 0;
}
