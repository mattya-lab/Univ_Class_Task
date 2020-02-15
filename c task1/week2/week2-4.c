#include <stdio.h>

int main(void)
{
    int x;
    float y;

    x = (683 - 119) * (8 + 21) / 41;
    y = (683 - 119) * (8 + 21) / 41;

    printf("Calulate Integer type : (683-119)*(8+21)/41=%d\n", x);
    printf("Calculate Floating point type : (683-119)*(8+21)/41=%.2lf\n", y);

  return 0;
}
