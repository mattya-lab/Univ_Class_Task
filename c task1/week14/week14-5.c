#include<stdio.h>

#define NUMBER (30)

double Lojistic_map(double an) {
    return 4 * an * (1 - an);
}

int main(void)
{
    FILE* fp1/*data.txt*/, * fp2/*data.bin*/;
    double x = 0.1, xt = 0.1, xb = 0.1;
    int i;

    for (i = 0; i < NUMBER; i++) { //n = 1-30
        printf("%2d: %lf %lf %lf\n", i + 1, x, xt, xb);
        x = Lojistic_map(x);
        xt = Lojistic_map(xt);
        xb = Lojistic_map(xb);
    }
    //write data on file
    if ((fp1 = fopen("data.txt", "w")) == NULL) //data.txt
        printf("\a Can't open file.\n");
    else {
        fprintf(fp1, "%lf\n", xt); fclose(fp1);
    }

    if ((fp2 = fopen("data.bin", "w")) == NULL) //data.bin
        printf("\a Can't open file.\n");
    else {
        fwrite(&xb, sizeof(double), 1, fp2); fclose(fp2);
    }
    printf("-------------\n");
    xt = 0; xb = 0;

    //read data
    if ((fp1 = fopen("data.txt", "r")) == NULL)
        printf("\a Can't open file.\n");
    else {
        fscanf(fp1, "%lf", &xt);
        fclose(fp1);
    }

    if ((fp2 = fopen("data.bin", "r")) == NULL)
        printf("\a Can't open file.\n");
    else {
        fread(&xb, sizeof(double), 1, fp2);
        fclose(fp2);
    }

    for (i = NUMBER; i < 2 * NUMBER; i++) { //n = 30-60
        printf("%2d: %lf %lf %lf\n", i + 1, x, xt, xb);
        x = Lojistic_map(x);
        xt = Lojistic_map(xt);
        xb = Lojistic_map(xb);
    }
    return 0;
}