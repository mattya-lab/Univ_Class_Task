#include<stdio.h>

#define BUFFER_SIZE 256

typedef struct results {
    int number;
    double english, mathmatic, japanese;
}Results;

int main(void)
{
    Results student[BUFFER_SIZE / 2] = {};
    int i = 0, num = 0;
    double english_sum = 0, mathmatic_sum = 0, japanese_sum = 0;
    double english_ave = 0, mathmatic_ave = 0, japanese_ave = 0;

    while (1) {
        printf("Input school ID number: \n"); scanf("%d", &student[i].number);
        if (student[i].number == 0000) break;
        printf("Input English score: \n"); scanf("%lf", &student[i].english);
        printf("Input Math score: \n"); scanf("%lf", &student[i].mathmatic);
        printf("Input Japanese score: \n"); scanf("%lf", &student[i].japanese);
        i++; num++;
    }

    for (i = 0; i < num; i++) {
        english_sum += student[i].english;
        mathmatic_sum += student[i].mathmatic;
        japanese_sum += student[i].japanese;
    }

    english_ave = english_sum / num;
    mathmatic_ave = mathmatic_sum / num;
    japanese_ave = japanese_sum / num;

    printf("English, Math, Japanese average score is %.1lf, %.1lf, %.1lf.\n",
        english_ave, mathmatic_ave, japanese_ave);
    return 0;
}