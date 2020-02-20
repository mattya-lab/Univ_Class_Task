#include <stdio.h>

void sort(int *left, int *right)
{
  if(*left < *right){
    *left = *right;
  }
}

int main(void)
{
    int a, b;

    printf("First number:  "); scanf("%d", &a);
    printf("Second number: "); scanf("%d", &b);

    sort(&a, &b);
    printf("Bigger number is %d.\n", a);

    return 0;
}
