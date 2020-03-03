#include<stdio.h> 
#include<stdlib.h>

int ALU(int x, int y, char z) {
    switch (z) {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    }
}

int main(void)
{
    /* Array a is number's stack, Array b is stack of arithmetic operator */
    /* Array exchange is a stack of changing string to integer*/
    /* spoint is Array a's stop point and  cspoint is array b's char_stop_point*/

    char text[31] = { "2*(2+3)+(6/3+2)" };
    /* Each increment */
    int i = 0, j = 0, k = 0, n = 0, q = 0;
    int a[15] = {}, x = 0, y = 0;
    int spoint = 0;
    int cspoint = 0;
    char exchange[7] = {};
    char b[15] = {}, z = {};


    printf("%s", text);

    /*start to split to each numbers and arithmetic operator */
    while (text[i] != '\0') {
        if ('0' <= text[i] && text[i] <= '9') {
            exchange[j] = text[i]; j++;
        }
        else {
            if (exchange[j - 1] != '\0' && j - 1 >= 0) { /* j's value is positive number */
                a[k] = atoi(exchange); k++;
                for (q = 0; q < j; q++)
                    exchange[q] = '\0';
                j = 0;
            }

            b[n] = text[i];
            if (text[i] == '(') {
                spoint = k;
                cspoint = n;
            }
            if (text[i] == ')') {
                while (1) {
                    b[n] = '\0';

                    x = a[(k - 1) - 1];  y = a[k - 1];  z = b[(n - 1)];

                    a[(k - 1) - 1] = ALU(x, y, z);
                    a[k - 1] = 0; b[n - 1] = '\0';
                    k = k - 1; n = n - 1;
                    if (n - 1 == cspoint) {
                        b[n - 1] = '\0';
                        break;
                    }
                }
                k = spoint; n = cspoint;
            }
            /* The relationship among b[n-1], b[n] and a[k] */
            if (b[n - 1] == '+' || b[n - 1] == '-' || b[n - 1] == '*' || b[n - 1] == '/') {
                if ((b[n] != '(' || b[n] != ')') && a[k] != 0) {
                    x = a[k - 1];  y = a[k];  z = b[n - 1];
                    a[k - 1] = ALU(x, y, z);
                    a[k] = 0; b[n - 1] = '\0'; n = n - 2;
                }
            }
            /* The relationship among b[n - 1], b[n] and a[k] */
            if ((b[n - 1] == '*' || b[n - 1] == '/') && (b[n] == '+' || b[n] == '-') && a[k] == 0) {
                x = a[k - 2]; y = a[k - 1]; z = b[n - 1];
                a[k - 2] = ALU(x, y, z);
                a[k - 1] = 0;
                b[n - 1] = b[n]; b[n] = '\0'; k = k - 1; n = n - 1;
            }
            n++;
        }
        i++;
    }

    //for (i = 4; i >= 0; i--)
        //printf("a[%d]: %d b[%d]: %c\n", i, a[i], i, b[i]);
    //printf("k: %d: n:%d\n", k, n);
    printf(" = %d\n", a[0]);
    return 0;
}