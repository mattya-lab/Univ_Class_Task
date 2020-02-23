#include <stdio.h>

int main(void)
{
    char c, * p;
    char s[12] = "Ritsumeikan";

    c = 'A';
    p = &c;

    printf("c: %c\n", c);     //c's character is 'A'
    printf("&c: %p\n\n", &c); //c's address
    printf("p: %p\n", p);     //c's address
    printf("*p: %c\n\n", *p); //c's character

    *p = 'B';

    printf("c: %c\n", c);     //c's character is 'B'
    printf("&c: %p\n\n", &c); //c's address
    printf("p:%p\n", p);      //c's address
    printf("*p: %c\n\n", *p); //c's character

    printf("s: %s\n", s);               //s is 'Ritsumeikan'
    printf("s[0]: %c\n", s[0]);         //s[0] is 'R'
    printf("s[1]: %c\n", s[1]);         //s[1] is 'i'
    printf("s: %p\n", s);               //s's first address
    printf("&s[0]: %p\n", &s[0]);       //s's first address
    printf("*s: %c\n", *s);             //s's character is 'R'
    printf("*(s+1): %c\n\n", *(s + 1)); //s's character is 'i'

    *(s + 2) = 'T';      //s' 3th index character change 't' to 'T'
    printf("s:%s\n", s); //s: string sentence

    return 0;

}
