#include <stdio.h>

int main(void)
{
    FILE* fp;
    char name[100];
    char menu[100];
    int price;

    if ((fp = fopen("gifts.dat", "r")) == NULL)
        printf("Can't open this file.\n");
    else {
        while (fscanf(fp, "%s %s %d", name, menu, &price) == 3) {
            printf("%s %s %d \n", name, menu, price);
        }
        fclose(fp);
    }
    return 0;
}
