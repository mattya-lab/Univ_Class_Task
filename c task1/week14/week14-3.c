#include <stdio.h>
#include <time.h>

char data_file[] = "datatime.dat";

void get_data(void)
{
    FILE* fp;
    if ((fp = fopen(data_file, "r")) == NULL)
    {
        printf("It is first time to execute this program.\n");
    }
    else
    {
        //Read file and get last operated time  
        int hour, min, sec;/*時間, 分, 秒*/
        fscanf(fp, "%d %d %d", &hour, &min, &sec);
        printf("Last operate time was %d hour %d minute %d second.\n", hour, min, sec);
        fclose(fp);
    }
}

void put_data(void)
{
    FILE* fp;
    time_t t = time(&t);
    struct tm* tm = localtime(&t);

    if ((fp = fopen(data_file, "w")) == NULL)
        printf("Can't open datatime.dat file.\n");
    else
    {
        //write now time on file
        fprintf(fp, "%d %d %d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
        fclose(fp);
    }
}

int main(void)
{
    get_data();
    put_data();

    return 0;
}
