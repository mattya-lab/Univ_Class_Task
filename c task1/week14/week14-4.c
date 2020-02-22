#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 255                

int main(void)
{
    FILE* fp;
    int a, b;
    char c[BUFFER_SIZE] = {};
    int d, e;

    /* Read file (fscanf) */
    if ((fp = fopen("Kesson.dat", "r")) == NULL) {
        printf("Can't open Kesson.dat file.\n");
    }
    else {
        fprintf(stdout, "-- fscanf() --------------------\n");
        while (fscanf(fp, "%d %d", &a, &b) == 2) {
            fprintf(stdout, "%d %d\n", a, b);
        }
        fprintf(stdout, "--------------------------------\n");
        fclose(fp);
    }
    putchar('\n');

    /*-------------------------------------------*/
    /* Read file (fgets) */
    if ((fp = fopen("Kesson.dat", "r")) == NULL) {
        printf("Can't open Kesson.dat file.\n");
    }
    else {
        fprintf(stdout, "-- fgets() ---------------------\n");
        while (fgets(c, BUFFER_SIZE, fp) != NULL) {
            /*
            sscanf(c, "%d %d", &d, &e);
            if (c[0] == ' ' || c[2] == ' '){
            */
            if (sscanf(c, "%d %d", &d, &e) != 2) {
                fprintf(stdout, "Missing data\n");
            }
            else {
                fprintf(stdout, "%d %d\n", d, e);
            }
        }
        fprintf(stdout, "--------------------------------\n");
        fclose(fp);
    }
    return 0;
}