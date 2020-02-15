#include <stdio.h>

int main(void)
{
  int date, day;

  puts("Find out the day of the week of April 2001 year: ");
  printf("Is the date you want to check ? "); scanf("%d", &date);

  day = (date + 0 - 1) % 7;

  if (date <= 0)
      printf("April 2001 starts from 1.\n");
  else if (31 <= date)
      printf("April 2001 has only 30 days.\n");
  else {
      switch (day) {
      case 0: printf("April %d, 2001 is Sunday.\n", date); break;
      case 1: printf("April %d, 2001 is Monday.\n", date); break;
      case 2: printf("April %d, 2001 is Tuesday.\n", date); break;
      case 3: printf("April %d, 2001 is Wednesday.\n", date); break;
      case 4: printf("April %d, 2001 is Thursday.\n", date); break;
      case 5: printf("April %d, 2001 is Friday.\n", date); break;
      case 6: printf("April %d, 2001 is Saturday.\n", date); break;
      default: printf("Error\n"); break;
      }
  }

  return 0;
}
