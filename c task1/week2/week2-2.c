#include <stdio.h>

int main(void)
{
  double x, y;

  printf("Input Floating point x value: ");
  scanf("%lf", &x);
  printf("Input Floating point y value: ");
  scanf("%lf", &y);

  printf("%.2lf * %.2lf = %.2lf\n", x, y, x * y);

  return 0;

}
