#include <stdio.h>
#include <math.h>

//------------------------------------------------
double interest(double r, int n){
  return pow((double)(1 + r/100), n);
}
//------------------------------------------------
int main(void){
  int y, n;
  double r;

  printf("Profit(r): "); scanf("%lf", &r);
  printf("Amount of money(y): "); scanf("%d", &y);
  printf("Period(n): "); scanf("%d", &n);
  
  printf("Repayment amount is %d.\n", (int)(y * interest(r, n) + 0.5));
  return 0;
}

/*pow((double)(1+r/100), n)でもよい*/
