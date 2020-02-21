#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 255
#define MAX_MEMBER 7

struct Profile
{
    int num;
    char Jname[BUFFER_SIZE];
    char Ename[BUFFER_SIZE];
    char address[BUFFER_SIZE];
};

int main(void)
{
    struct Profile profile[MAX_MEMBER] = {};;
    int cnt = 1;
    int i;

    profile[0].num = cnt;
    strcpy(profile[0].Jname, "立命太郎");
    strcpy(profile[0].Ename, "ritsumei taro");
    strcpy(profile[0].address, "滋賀県草津市野路東1-1-1");
    cnt++;

    profile[1].num = cnt;
    strcpy(profile[1].Jname, "衣笠 花子");
    strcpy(profile[1].Ename, "kinugasa hanako");
    strcpy(profile[1].address, "京都府京都市北区等持院北町56-1");
    cnt++;

    profile[2].num = cnt;
    strcpy(profile[2].Jname, "朱雀 二朗");
    strcpy(profile[2].Ename, "suzaku jiro");
    strcpy(profile[2].address, "京都府京都市中京区西ノ京朱雀町1");
    cnt++;

    for (i = 0; i < 3; i++) {
        printf("School ID number: %d\n", profile[i].num);
        printf("Name: %s\n", profile[i].Jname);
        printf("Name(Roman character): %s\n", profile[i].Ename);
        printf("Address:%s\n", profile[i].address);
        printf("\n");
    }
    return 0;
}
