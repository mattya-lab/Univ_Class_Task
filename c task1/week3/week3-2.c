#include <stdio.h>

int main(void)
{
    printf("Score(Max: 100): ");
    scanf("%d", &x);

    if (90 <= x && x <= 100) printf("Rating is A+.\n");
    else if (80 <= x && x <= 89) printf("Rating is A.\n");
    else if (70 <= x && x <= 79) printf("Rating is B.\n");
    else if (60 <= x && x <= 69) printf("Rating is C.\n");
    else if (0 <= x && x <= 59) printf("Rating is F.\n");
    else printf("Error\n");

  return 0;
}
