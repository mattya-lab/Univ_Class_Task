#include<stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main(void)
{
    int a, b, c;

    printf("Input the length of three sides as an integer type.\n");
    printf("First side: "); scanf("%d", &a);
    printf("Second side: "); scanf("%d", &b);
    printf("Third side: "); scanf("%d", &c);

    if (a < b)
        swap(&a, &b);
    if (a < c)
        swap(&a, &c);
    if (b < c)
        swap(&b, &c);

    if (a >= b + c) {
        printf("3 sides %d %d %d don't make a triangle.\n", a, b, c);
    }
    else {
        /* Right angle */
        if (a * a == b * b + c * c)
            printf("3 sides %d %d %d is right triangle.\n", a, b, c);

        /* Obtuse angle */
        else if (a * a >= b * b + c * c) {
            printf("3 sides %d %d %d is obtuse triangle.\n", a, b, c);
            if (b == c)
                printf("And also an isosceles triangle.\n");
        }

        /* Acute angle */
        else { //if (a * a <= b * b + c * c) {
            printf("3 sides %d %d %d is acute triangle.\n", a, b, c);
            if (a == b && a == c && b == c)
                printf("More equilateral triangle\n");
        }
    }

  return 0;
}
