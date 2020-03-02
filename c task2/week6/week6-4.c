#include<stdio.h>

void print_stack_ary(char* s, int top);
char pop(char* s, int* top);
void push(char c, char* s, int* top);

int main(void) {

    char s[15];
    int top = 0;
    char x, y;
    int rc;

    while (1) {
        printf("Inpt a  character(0: Exit, 1: Pop_up, other: Push_down): ");
        scanf("%c", &x); getchar();
        if (x == '0') {
            printf("Exit\n");
            break;
        }
        else if (x == '1') {
            if (top == 0)
                printf("Empty\n");
            else {
                y = pop(s, &top); print_stack_ary(s, top);
                printf("pop= %c top= %d\n", y, top + 1);
            }
        }
        else {
            push(x, s, &top); print_stack_ary(s, top);
        }
    }
    return 0;
}

char pop(char* s, int* top) {
    char y;
    (*top)--; y = s[*top];
    return y;
}

void push(char c, char* s, int* top) {
    s[*top] = c; (*top)++;
}

void print_stack_ary(char* s, int top) {
    int i;
    printf("<---TOP=%d\n", top);
    for (i = top - 1; i >= 0; i--)
        printf("%c\n", s[i]);
}
