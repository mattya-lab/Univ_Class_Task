#include <stdio.h>

int main()
{
  int a;   
  int b;
  int *p;  
  int **pp;

  a = 10;
  b = 20;
  p = &a;
  pp = &p;
  printf("[p = &a; ]\n");
  printf("[pp = &p;]\n");
  
  printf("a:    %d\n", a);
  putchar('\n');

  printf("p:    %p\n", p);   
  printf("*p:   %d\n", *p);  
  printf("&p:   %p\n", &p);  
  putchar('\n');

  printf("pp:   %p\n", pp);  
  printf("*pp:  %p\n", *pp); 
  printf("**pp: %d\n", **pp);
  putchar('\n');
  

  if( *pp == p ) printf("(*pp == p)\n");
  else           printf("(*pp != p)\n");

  
  if( *p == a )  printf("(*p == a)\n");
  if( *p == b )  printf("(*p == b)\n");
  putchar('\n');

  
  *pp = &b;
  printf("[*pp = &b;]\n");

  printf("b:    %d\n", b);
  putchar('\n');

  printf("p:    %p\n", p);   
  printf("*p:   %d\n", *p);  
  printf("&p:   %p\n", &p);  
  putchar('\n');

  printf("pp:   %p\n", pp);  
  printf("*pp:  %p\n", *pp); 
  printf("**pp: %d\n", **pp);
  putchar('\n');

  
  if( *pp == p ) printf("(*pp == p)\n");
  else           printf("(*pp != p)\n");

  
  if( *p == a )  printf("(*p == a)\n");
  if( *p == b )  printf("(*p == b)\n");
  putchar('\n');
  
  return 0;
}
