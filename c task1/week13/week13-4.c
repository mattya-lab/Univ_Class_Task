#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256
#define MEMBER 5

struct Profile {
    int num, age, h, w;
    char name[BUFFER_SIZE], birth[BUFFER_SIZE], special[BUFFER_SIZE];
};

void swap(struct Profile* x, struct Profile* y)
{
    struct Profile temp = *x;
    *x = *y;
    *y = temp;
}

void sort(struct Profile profile[], int num)
{
    int i, j;

    for (i = 0; i < (num - 1); i++)
        for (j = (num - 1); j > i; j--)
            if (profile[j - 1].h < profile[j].h)
                swap(&profile[j - 1], &profile[j]);
}

int main(void)
{
    struct Profile profile[MEMBER];
    int cnt = 0;
    int i;

    profile[0].num = cnt;
    strcpy(profile[0].name, "立命 太郎");
    profile[0].age = 20;
    profile[0].h = 175;
    profile[0].w = 65;
    strcpy(profile[0].birth, "滋賀");
    strcpy(profile[0].special, "英会話");
    cnt++;

    profile[1].num = cnt;
    strcpy(profile[1].name, "草津 二朗");
    profile[1].age = 22;
    profile[1].h = 180;
    profile[1].w = 65;
    strcpy(profile[1].birth, "京都");
    strcpy(profile[1].special, "プログラミング");
    cnt++;

    profile[2].num = cnt;
    strcpy(profile[2].name, "衣笠 花子");
    profile[2].age = 21;
    profile[2].h = 160;
    profile[2].w = 52;
    strcpy(profile[2].birth, "大阪");
    strcpy(profile[2].special, "スポーツ全般");
    cnt++;

    profile[3].num = cnt;
    strcpy(profile[3].name, "茨木　華子");
    profile[3].age = 20;
    profile[3].h = 162;
    profile[3].w = 55;
    strcpy(profile[3].birth, "京都");
    strcpy(profile[3].special, "プログラミング");
    cnt++;

    profile[4].num = cnt;
    strcpy(profile[4].name, "滋賀 三朗");
    profile[4].age = 22;
    profile[4].h = 168;
    profile[4].w = 70;
    strcpy(profile[4].birth, "大阪");
    strcpy(profile[4].special, "英語");
    cnt++;

    sort(profile, cnt);

    for (i = 0; i < MEMBER; i++) {
        printf("Number: %d:\n", profile[i].num);
        printf("Name: %s:\n", profile[i].name);
        printf("Age: %d:\n", profile[i].age);
        printf("Height: %d\n", profile[i].h);
        printf("Body Weight :%d\n", profile[i].w);
        printf("From: %s\n", profile[i].birth);
        printf("Special skill: %s\n", profile[i].special);
        printf("\n");
    }

    return 0;
}
