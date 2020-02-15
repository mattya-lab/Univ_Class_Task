#include<stdio.h>

int main(void)
{
  double num1=1, num2=0, num3;

  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;
  num2 = num2 + 0.1;

  num3 = num1 - num2;

  printf("num1 = %lf : num2 = %lf : \nnum3 =  %.23lf\n", num1, num2, num3);

  return 0;
}
