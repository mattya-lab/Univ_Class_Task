#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 256
#define MEMBER 3

struct Profile
{
    int num;
    char Jname[BUFFER_SIZE];
    char Ename[BUFFER_SIZE];
    char address[BUFFER_SIZE];
};

void print_data(struct Profile data[]);

int main(void)
{
    struct Profile data[MEMBER];
    int cnt = 1;
    int i;

    data[0].num = cnt;
    strcpy(data[0].Jname, "立命太郎");
    strcpy(data[0].Ename, "ritsumei taro");
    strcpy(data[0].address, "滋賀県草津市野路東1-1-1");
    cnt++;

    data[1].num = cnt;
    strcpy(data[1].Jname, "衣笠 花子");
    strcpy(data[1].Ename, "kinugasa hanako");
    strcpy(data[1].address, "京都府京都市北区等持院北町56-1");
    cnt++;

    data[2].num = cnt;
    strcpy(data[2].Jname, "朱雀 二朗");
    strcpy(data[2].Ename, "suzaku jiro");
    strcpy(data[2].address, "京都府京都市中京区西ノ京朱雀町1");
    cnt++;

    print_data(data);
    return 0;
}

void print_data(struct Profile data[])
{
    int i;
    for (i = 0; i < MEMBER; i++) {
        printf("School ID number: %d\n", i + 1);
        printf("Name: %s\n", data[i].Jname);
        printf("Name(Roman character): %s\n", data[i].Ename);
        printf("Address: %s\n", data[i].address);
        printf("\n");
    }
}
