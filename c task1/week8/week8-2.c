#include <stdio.h>
#include <math.h>
#define NUMBER 512

double nolm(int v[], int n)
{
  int i;
  double nolm=0;

  for(i = 0; i < n; i++){
    nolm += v[i] * v[i];
  }

  nolm = sqrt(nolm);

  return nolm;
}

int main(void)
{
  int i, n;
  int v[NUMBER];

  while (1) {
      printf("Is element's size in the vector.(Max 512)? ");
      scanf("%d", &n);
      if (0 <= n && n <= NUMBER)
          break;
      else
          printf("Please reduce the element's size to %d or less.\n", NUMBER);
  }

  for (i = 0; i < n; i++) {
      printf("%d index's elements: ", i + 1);
      scanf("%d", &v[i]);
  }

  printf("This vector's nolm is %lf\n", nolm(v, n));


  return 0;
}
