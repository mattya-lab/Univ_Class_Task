#include<stdio.h>

#define BUFFER_SIZE 255

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
    int i = 0, j, cnt = 0;
    int Array[BUFFER_SIZE] = {};

    while (1) {
        printf("Positive number: "); scanf("%d", &Array[i]);
        if (Array[i] == 0)
            break;
        i++;
        cnt++;
    }

    for (i = 0; i < cnt; i++) {/*o(n*n)*/
        for (j = 0; j < cnt; j++) {
            if (Array[j] > Array[j + 1])
                swap(&Array[j], &Array[j + 1]);
        }
    }

    printf("Sort numbers inputed value in ascending order: ");
    for (i = 0; i < cnt; i++)
        printf("%2d, ", Array[i]);
    printf("%2d\n", Array[cnt]);

    return 0;
}
      
