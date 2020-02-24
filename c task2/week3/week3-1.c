#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char* a, * b;
    int size;

    printf("Input string sentence's length size.:");  scanf("%d", &size);
    a = (char*)malloc(sizeof(char) * (size + 1)); /* +1 is memory of '\0' */

    if (a == NULL) printf("Errorです\n");
    else {
        printf("Input string sentence: "); scanf("%s", a);
        b = a;
        while (*b != '\0')
            b++;
        while (a < b) {
            b--;
            putchar(toupper(*b));
        }
        putchar('\n');
    }
    free(a);

    return 0;
}
