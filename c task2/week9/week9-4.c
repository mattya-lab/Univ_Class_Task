#include<stdio.h>

struct data {
    char name[15], area[15];
    int  population;
};

int i = 0, j = 0, num = 0;
FILE* fp;
struct data countries[16];

void Print() {
    for (i = 0; i < num; i++)
        printf("%s %s %d\n",
            countries[i].name, countries[i].area, countries[i].population);
}

void Download() {
    char country[15] = {}, area[15] = {};
    int population = 0;

    if ((fp = fopen("countries16.dat", "r")) == NULL) {
        printf("Don't Open\n"); fclose(fp);
    }
    else {
        while (fscanf(fp, "%s %s %d", country, area, &population) == 3) {
            strcpy(countries[i].name, country);
            strcpy(countries[i].area, area);
            countries[i].population = population;
            i++; num++;
        }
        fclose(fp);  printf("\n");
    }
}

void swap(struct data* x, struct data* y)
{
    struct data temp = (*x);
    (*x) = (*y);
    (*y) = temp;
}

void Bubblesort() {
    int temp;
    printf("----------Bubblesort----------\n");
    for (i = 0; i < num - 1; i++) {
        for (j = num - 1; j > i; j--) {
            if (countries[j - 1].population > countries[j].population) {
                swap(&countries[j - 1], &countries[j]);
            }
        }
    }
}

int main(void) {
    Download();
    Print();
    Bubblesort();
    Print();
    return 0;
}