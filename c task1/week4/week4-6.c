#include<stdio.h>

int main(void)
{
    int date, last_day, day = 1;
    int i, week_cnt = 0, space_cnt = 0;

    do {
        printf("What date is the first day of the month?: SUN(1) MON(2) TUE(3) WED(4) THU(5) FRI(6) SAT(7): "); scanf("%d", &date);
    } while (date < 1 || 7 < date);

    do {
        printf("What day is the end of the month?: 28 day more, 31 day or less: "); scanf("%d", &last_day);
    } while (last_day < 28 || 31 < last_day);


    printf("SUN MON TUE WED THU FRI SAT\n");

    for (i = 0; i < date - 1; i++) {
        printf("    ");
        week_cnt++;
        space_cnt++;
    }

    for (i = date - 1; i < last_day + space_cnt; i++) {
        printf("%2d  ", day);
        week_cnt++;
        day++;
        if (week_cnt % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
  
  return 0;
}
