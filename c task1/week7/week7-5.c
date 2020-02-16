#include<stdio.h>
#define MONTH (12)

int leapYear(int year){
  if((year % 4) == 0){
    if((year % 400) == 0)   year = 1;
    else if((year % 100) == 0)   year = 0;
    else  year = 1;
  }
  else{
    year = 0;
  }
  
  return year;
}

int main(void){
    int i;
    int year, month, day, max_month_day, future = 10000;

    printf("What year, what month, and whate date ?\n");
    printf("Year: ");  scanf("%d", &year);
    printf("Month: ");  scanf("%d", &month);
    printf("Date: ");  scanf("%d", &day);
    day = day - 1;

    for (i = 10000; i >= 0; i--) {
        /*January, March, May, July, August, October, December == 31*/
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
            month == 10 || month == 12)
            max_month_day = 31;
        /*April, June, September, November == 29*/
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            max_month_day = 30;
        /*February == 28 or 29*/
        else if (leapYear(year) == 1 && month == 2) max_month_day = 29;
        else max_month_day = 28;

        day++;

        if (day > max_month_day) {
            month = month + 1;
            day = 1;
        }

        if (month > MONTH) {
            year = year + 1;
            month = 1;
        }
    }

    printf("10000 days later is %d / %d / %d .\n", year, month, day);

    return 0;
}
