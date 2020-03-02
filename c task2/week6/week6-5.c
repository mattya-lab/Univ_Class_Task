#include<stdio.h>
#define MAX (15)

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

int main(void) {
    int i, flag = 0, top = 0, top_2 = 0;
    char stack[15], stack_2[15], x, y;

    while (1) {
        printf("Input 1 character(0: Exit, 1: Pop_up, Other: Push_down): ");
        scanf("%c", &x); getchar();

        if (x == '0') {
            printf("Exit\n");
            break;
        }
        else if (x == '1') { /* pop_up */
            if (top == 0)
                printf("Empty\n");
            else {
                y = pop(stack, &top);
                print_stack_ary(stack, top);
                printf("pop= %c top= %d\n", y, top + 1);
            }
        }
        else { /* push_down */
            /* State A -> State B*/
            for (i = top; i >= 0; i--) {
                if (x == stack[i]) {
                    flag = 1;
                    continue;
                }
                else {
                    /*stack_2 pop*/
                    push(stack[i], stack_2, &top_2);
                }
            }
            /* stack_2 */
            printf("check_stack_2\n");
            for (i = top_2 - 1; i > 0; i--)
                printf("%c\n", stack_2[i]);

            /* state B -> state C */
            for (i = 0; i <= top; i++) {
                /*stack_1 push_down : stack_2 pop_up*/
                top_2--; stack[i] = stack_2[top_2];
            }

            if (flag == 0)/*option6-4*/
                push(x, stack, &top);
            else
                top--;

            /* stack_1 */
            printf("check_stack_1\n"); print_stack_ary(stack, top);
            /* initialize */
            flag = 0; top_2 = 0;
        }
    }
    return 0;
}
