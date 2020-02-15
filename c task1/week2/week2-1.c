#include <stdio.h>

int main(void)
{
  int x, y;

  printf("Input First value: ");  scanf("%d", &x);
  printf("Input Second value: "); scanf("%d", &y);

  printf("%d / %d = %d, %d %% %d = %d\n", x, y, x / y, x, y, x % y);

  return 0;
} 
  
