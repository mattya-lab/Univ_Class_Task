#include <stdio.h>
#include <stdlib.h>

#define NUMBER (5)
#define BUFFER_SIZE (64)

int main(void) {
    char* name[NUMBER];
    int i, n;
    printf("Input some names less than Max %d men or women: \n", NUMBER);

    for (i = 0; i < NUMBER; i++) {
        name[i] = (char*)malloc(sizeof(char) * (BUFFER_SIZE));

        if (scanf("%s", name[i]) == EOF) {
            n = i;
            break;
        }
        else
            n = 5;
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%p %s\n", &name[i], name[i]);
        free(name[i]);
    }
    return 0;

}
