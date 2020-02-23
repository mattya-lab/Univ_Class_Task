#include<stdio.h>

#define BUFFER_SIZE (255)
#define MAX_ID (1000)

struct data{
    int idnum;
    char name[BUFFER_SIZE];
    char gen;
    double eng;
    double math;
};
  
int main(void){
    FILE *fp, *fp2;
    struct data yomikomi[MAX_ID], kakikomi[MAX_ID];  /* yomikomi means 'read', kakikomi means 'write' in Japanese*/
    int i=0/* increment */, cnt;
  
    /* Seiseki.dat---store struct kakikomi */
    if( ( fp = fopen("Seiseki.dat", "r") ) == NULL){
        printf("Can't open Seiseki.dat file.\n");
        fclose(fp);
    }
    else{
        while(fscanf(fp, "%s %c %lf %lf",
		     kakikomi[i].name, &kakikomi[i].gen,
		     &kakikomi[i].eng, &kakikomi[i].math) == 4){
             kakikomi[i].idnum = i; /*id = 0....*/
            i++;
        }
        fclose(fp);
    }  

    /* Open Seiseki.bin -- write struct kakikomi on .bin format file */
    if( (fp2 = fopen("Seiseki.bin", "w") ) == NULL){
        printf("Can't open Seiseki.bin file.\n");
        fclose(fp2);
    }
    else{
        fwrite(&kakikomi, sizeof(kakikomi), i, fp2);
        fclose(fp2);
    }

    /* Open Seiseki.bin -- read struct yomikomi on .bin format fike */
    if( (fp2 = fopen("Seiseki.bin", "r") ) == NULL){
        printf("Can't open Seiseki.bin file.\n");
        fclose(fp2);
    }
    else{
        fread(&yomikomi, sizeof(yomikomi), i, fp2);
        fclose(fp2);
    }

    /* Output information toward ID number. */
    printf("Which data do you refer to ? ID[0-%d]: ", i-1);  scanf("%d", &cnt);

    if(-1 < cnt && cnt < i)
        printf("%d %s %c %lf %lf\n", yomikomi[cnt].idnum, yomikomi[cnt].name,
	            yomikomi[cnt].gen, yomikomi[cnt].eng, yomikomi[cnt].math);
    else
        printf("Not exsit such a data.\n");

  return 0;
}
