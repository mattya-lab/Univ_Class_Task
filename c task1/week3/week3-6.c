#include<stdio.h>

int main(void)
{
    int student_number = 1234, english = 94, math = 78;
    int select;

    printf("Current Grade Information is Student ID number: %d, English: %d, Math: %d\n", student_number, english, math);
    printf("[0] Correction of student ID number\n");
    printf("[1] Correction of English score\n");
    printf("[2] Correction of Math score\n");
    printf("Which command to execute ?: "); scanf("%d", &select);

    switch (select) {
    case 0: printf("Input a new student ID number.: "); scanf("%d", &student_number); break;
    case 1: printf("Input a new English score.: "); scanf("%d", &english); break;
    case 2: printf("Input a new Math score.: "); scanf("%d", &math); break;
    default:printf("Grade information isn't updated because there is no corresponding command\n"); break;
    }

    printf("Current Grade Information is Student ID number: %d, English: %d, Math: %d\n", student_number, english, math);
    
    return 0;
}
  
