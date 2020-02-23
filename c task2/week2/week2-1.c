#include <stdio.h>

int main(void)
{
    int a,*p;

    a = 10;  //a is 10
    printf("a:%d\n",a);     //a's value
    printf("&a:%p\n\n",&a); //a's address

    p = &a;
    printf("p:%p\n",p);     //a's address
    printf("*p:%d\n",*p);   //a's value
    printf("&p:%p\n\n",&p); //p's address

    a = 20; 
    printf("a:%d\n",a); 
    printf("&a:%p\n\n",&a);

    printf("p: %p\n",p); 
    printf("*p: %d\n",*p); 
    printf("&p: %p\n",&p);

     return 0;
}
