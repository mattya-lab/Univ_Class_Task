#include <stdio.h>
#include <math.h>
#define NUMBER 512

int naiseki(int x[], int y[], int n)
{ 
    int i, naiseki=0;
  
    for(i=0; i<n; i++)
        naiseki +=x[i]*y[i];

    return naiseki;
} 

double root_v(int v[], int n)
{
    int i;
    double x = 0, root_v;

    for(i=0; i<n; i++){
        x +=v[i]*v[i];
    }
    root_v=sqrt(x);
    return root_v;
}

int main(void)
{
    int i, n;
    int x[NUMBER], y[NUMBER];
    double cos;

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

    cos = naiseki(x, y, n) / (root_v(x, n) * root_v(y, n));
    printf("cos's value is %lf.\n", cos);


    return 0;
}
