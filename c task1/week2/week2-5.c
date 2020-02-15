#include<stdio.h>

int main(void)
{
  char str1 = -128, str2 = 127;
  str1 = str1 - 1;
  str2 = str2 + 1;

  printf("str1 = %d : str2 = %d\n", str1, str2);
  return 0;
}
