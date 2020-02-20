#include<stdio.h>
#define BUFFER_SIZE 256

char str_copy_cnt(char *a, const char *b)
{
  int cnt=0;
  do{
    cnt++;
  }while(*a++ = *b++);

  cnt -= 1;

  return cnt;
}

int main(void)
{
  char str_i[BUFFER_SIZE]={}, str_o[BUFFER_SIZE]={};
  int n;

  printf("Input string sentence(Max % d): ", BUFFER_SIZE);
  fgets(str_i, 256, stdin);
  str_i[strlen(str_i) - 1] = '\0';

  printf("Before copy array str_i is %s.\n",str_i);

  n = str_copy_cnt(str_o,str_i);

  printf("After copy array str_o is %s.\n",str_o);
  printf("String sentence copied is %d.\n", n);

  return 0;
}
