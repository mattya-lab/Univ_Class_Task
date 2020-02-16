#include <stdio.h>
#define NUMBER 5
#define SUBJECT 4

int main(void)
{
    int i, j;
    int score[NUMBER][SUBJECT] = { {85,74,63,90},
                                   {78,65,70,62},
                                   {89,92,88,76},
                                   {32,48,66,25},
                                   {92,76,81,98} };

    double subject_ave[SUBJECT] = {};
    double subject_sum;
    double student_sum;

    for (i = 0; i < SUBJECT; i++) {
        subject_sum = 0;
        for (j = 0; j < NUMBER; j++) {
            subject_sum += score[j][i];
        }
        subject_ave[i] = subject_sum / NUMBER;

        switch (i) {
        case 0: printf("Japanese average score is %.1lf.\n", subject_ave[i]); break;
        case 1: printf("Math average score is %.1lf.\n", subject_ave[i]); break;
        case 2: printf("Science average score is %.1lf.\n", subject_ave[i]); break;
        case 3: printf("Society average score is %.1lf.\n", subject_ave[i]); break;
        }
    }


    for (i = 0; i < NUMBER; i++) {
        student_sum = 0;
        for (j = 0; j < SUBJECT; j++)
            student_sum += score[i][j];
        printf("Number %d sudent's average score is %.1lf.\n",
            i + 1, (double)student_sum / SUBJECT);
    }

    return 0;
}  
 
