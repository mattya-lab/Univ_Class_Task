#include <stdio.h>

#define BIN_WIDTH   25                
#define BIN_NUM     8                 

int main(void)
{
    FILE* fp;
    char name[100] = {}, gen;
    double eng, math;
    double sum;
    int num[BIN_NUM] = {};
    int i, j;

    if ((fp = fopen("Seiseki.dat", "r")) == NULL) {
        printf("Can't open Seiseki.dat file.\n");
        fclose(fp);
    }
    else {
        while (fscanf(fp, "%s %c %lf %lf", name, &gen, &eng, &math) == 4) {
            sum = eng + math;
            if (sum < 25) num[0]++;
            else if (sum < 50) num[1]++;
            else if (sum < 75) num[2]++;
            else if (sum < 100) num[3]++;
            else if (sum < 125) num[4]++;
            else if (sum < 150) num[5]++;
            else if (sum < 175) num[6]++;
            else if (sum <= 200) num[7]++;
        }
    }

    for (i = 0; i < BIN_NUM; i++) {
        printf("%3d ~ %3d : %d ", i * BIN_WIDTH, (i + 1) * BIN_WIDTH - 1, num[i]);
        for (j = 0; j < num[i]; j++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
