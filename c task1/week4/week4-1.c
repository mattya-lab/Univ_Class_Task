#include <stdio.h>

int main(void)
{
    int stone, cnt = 1, step = 1;

    printf("King, Number of stone?: "); scanf("%d", &stone);

    while (stone >= cnt) {
        stone = stone - cnt;
        step = step + 1;
        cnt = step * step;
    }
    printf("Pyramids of thst number of stones are %d steps, left %d stones.\n", (step - 1), stone);

    return 0;
}
