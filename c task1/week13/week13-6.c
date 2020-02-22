#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256
#define MEMBER (5) 

struct Salary {
    int base, housing, family;
};

struct Profile {
    int  id;
    char name[BUFFER_SIZE];
    int age, year;
    struct Salary salary;
};

int main(void)
{
    /* Profile construct of id, name, age, year, salary.base, salary.housing, salary.family*/
    struct Profile profile[MEMBER] = { {1001,"立命五郎",40,20,300000,15000,20000},
                                       {1002,"草津太郎",38,18,200000,15000,20000},
                                       {1003,"滋賀次郎",28, 5,200000,12000,    0},
                                       {1004,"衣笠佳子",26, 5,200000,15000,12000},
                                       {1005,"茨木三郎",22, 2,180000, 8000,    9} };
    int select, num;
    printf("Input Employee number: "); scanf("%d", &select);

    switch (select) {
    case 1001: num = 0; break;
    case 1002: num = 1; break;
    case 1003: num = 2; break;
    case 1004: num = 3; break;
    case 1005: num = 4; break;
    default: num = -1;  printf("No number\n"); break;
    }
    if (0 <= num && num <= 4) {
        printf("Name: %s, Age: %d, Workyear: %d, Salary: %d\n",
            profile[num].name, profile[num].age, profile[num].year,
            profile[num].salary.base + profile[num].salary.housing + profile[num].salary.family);
    }
    return 0;
}
}
