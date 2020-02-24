#include <stdio.h>

int main(void)
{
    const char* p1, * p2;  //address's contentアドレスの内容

    p2 = "Winter";         //address
    p1 = p2;               //p1 = winter

    while (*p1 != '\0'){   //search the last index element of string sentence
        p1++;
    }
    while (p1 > p2) {      //compare p1 and  p2 address 
        p1--;
        putchar(*p1);
    }
    putchar('\n');
    return 0;
}
