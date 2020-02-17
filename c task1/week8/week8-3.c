#include <stdio.h>
#define NUMBER 512

int naiseki(int x[], int y[], int n)
{
    int i, naiseki = 0;

    for (i = 0; i < n; i++)
        naiseki += x[i] * y[i];

    return naiseki;
}

int main(void)
{
     int i, n;
     int x[NUMBER];
     int y[NUMBER];

     while (1) {
         printf("Is the element's size in the vector? (Max 512): ");
         scanf("%d", &n);
         if (0 <= n || n <= 512)
              break;
         else
              printf("Please reduce the elements's size to 512 or less.\n");
     }

     for (i = 0; i < n; i++) {
         printf("Vector x[%d] element: ", i + 1); scanf("%d", &x[i]);
     }

     for (i = 0; i < n; i++) {
         printf("Vector y[%d]  element: ", i + 1); scanf("%d", &y[i]);
     }

     printf("Inner product of Vector x, y is %d.\n", naiseki(x, y, n));

     return 0;
}
  
