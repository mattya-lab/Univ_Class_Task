#include <stdio.h>

int main(void)
{
    FILE* fp, * mfp, * ffp;
    char name[100], gen;
    double eng, math;
    int ch;

    if ((fp = fopen("Seiseki.dat", "r")) == NULL) {
        printf("Can't open Seisei.dat file.\n");
    }
    else {
        while (fscanf(fp, "%s %c %lf %lf", name, &gen, &eng, &math) == 4) {
            if (gen == 'm') {
                if ((mfp = fopen("Male.dat", "a")) == NULL)
                    printf("dame");
                else {
                    fprintf(mfp, "%-15s %c %5.1lf %5.1lf\n", name, gen, eng, math);
                    fclose(mfp);
                }
            }
            else if (gen == 'f') {
                if ((ffp = fopen("Female.dat", "a")) == NULL)
                    printf("dame");
                else {
                    fprintf(ffp, "%-15s %c %5.1lf %5.1lf\n", name, gen, eng, math);
                    fclose(ffp);
                }
            }
        }
        fclose(fp);
    }

    return 0;
}