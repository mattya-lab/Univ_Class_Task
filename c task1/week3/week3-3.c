#include <stdio.h>

int main(void)
{
    int x;

    printf("What month is it now ?: "); scanf("%d", &x);

    if (3 <= x && x <= 5) printf("It's Spring.\n");
    else if (6 <= x && x <= 8) printf("It's Summer.\n");
    else if (9 <= x && x <= 11) printf("It's Fall/Autumn\n");
    else if (x == 12 || x == 1 || x == 2) printf("It's Winter.\n");
    else printf("Error!!\n");

  return 0;
}
