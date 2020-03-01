/*データの登録,検索,更新,削除が行える電話帳プログラム*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define BUFFER_SIZE (255)

FILE* fp;

int i = 0, j = 0, num = 0;

/* Telephone structure */
struct Telephone {
    int id;  /*example 0001*/
    char name[31], birth[15], number[15];
};

struct Telephone telephone[BUFFER_SIZE];

void Download() {
    if ((fp = fopen("telephone.txt", "r")) == NULL) {
        printf("Don't Open\n"); fclose(fp);
    }
    else {
        while (fscanf(fp, "%d %s %s %s",
            &telephone[i].id, telephone[i].name, telephone[i].birth, telephone[i].number) == 4) {
            i++; num++;
        }
        fclose(fp);
    }
}

void Reading() {
    if ((fp = fopen("telephone.txt", "w")) == NULL)
        printf("First Write\n");
    else {
        for (i = 0; i < num; i++) {
            fprintf(fp, "%d %s %s %s\n",
                telephone[i].id, telephone[i].name,
                telephone[i].birth, telephone[i].number);
        }
        fclose(fp);
    }
}

void Register() {
    telephone[num].id = num;
    printf("ex: name 20160101 000-0000-0000\n ");
    printf("name: "); scanf("%s", telephone[num].name);
    printf("birth: "); scanf("%s", telephone[num].birth);
    printf("phone number: "); scanf("%s", telephone[num].number); num++;
}

void Search()
{
    int search /* searxh condition */;
    int search_id;
    char search_name[31], search_birth[15], search_number[15];
    bool search_flag = false;

    printf("How to search?(1: ID 2: name 3: birth 4: phone number): ");
    scanf("%d", &search);

    switch (search) {
    case 1:
        printf("id: "); scanf("%d", &search_id); getchar();
        for (i = 0; i < num; i++) {
            if (i == search_id) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);
                search_flag = true;
            }
        }
        if (search_flag == false)
            printf("Not Exist The id.\n\n");
        break;

    case 2:
        printf("name: "); scanf("%s", search_name); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(search_name, telephone[i].name) == 0) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);
                search_flag = true;
            }
        }
        if (search_flag == false)
            printf("Not Exists The name.\n\n");
        break;

    case 3:
        printf("birth: "); scanf("%s", search_birth); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(search_birth, telephone[i].birth) == 0) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);
                search_flag = true;
            }
        }
        if (search_flag == false)
            printf("Not Exists The birth.\n\n");
        break;

    case 4:
        printf("number: "); scanf("%s", search_number); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(search_number, telephone[i].number) == 0) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);
                search_flag = true;
            }
        }
        if (search_flag == false)
            printf("Not Exist number.\n\n");
        break;

    default:
        printf("ERROR\n\n");
        getchar();
        break;
    }
}

void Update() {
    int update, search, key;
    int update_id;
    char update_name[31], update_birth[15], update_number[15];
    bool update_flag = false;

    printf("How to search(1: ID 2: name 3: birth 4: number : ");
    scanf("%d", &search);

    switch (search) {
    case 1:
        printf("id: "); scanf("%d", &update_id); getchar();
        for (i = 0; i < num; i++) {
            if (i == update_id) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);
                key = i;
                update_flag = true;
            }
        }
        if (update_flag == false)
            printf("Not Exist The id.\n\n");
        break;

    case 2:
        printf("name: "); scanf("%s", update_name); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(update_name, telephone[i].name) == 0) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);

                key = i;
                update_flag = true;
            }
        }
        if (update_flag == false)
            printf("Not Exists The name.\n\n");
        break;

    case 3:
        printf("birth: "); scanf("%s", update_birth); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(update_birth, telephone[i].birth) == 0) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);

                key = i;
                update_flag = true;
            }
        }
        if (update_flag == false)
            printf("Not Exists The birth.\n\n");
        break;

    case 4:
        printf("number: "); scanf("%s", update_number); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(update_number, telephone[i].number) == 0) {
                printf("%d %s %s %s\n\n",
                    telephone[i].id, telephone[i].name,
                    telephone[i].birth, telephone[i].number);

                key = i;
                update_flag = true;
            }
        }
        if (update_flag == false)
            printf("Not Exist number.\n\n");
        break;

    default:
        printf("ERROR\n\n");
        getchar();
        break;
    }
    if (update_flag == false) {}
    else {
        printf("Update(0: id 1: name 2: birth 3: number)"); scanf("%d", &update);

        switch (update) {
        case 0:
            printf("Update id: "); scanf("%d", &telephone[key].id); break;
        case 1:
            printf("Update name: "); scanf("%s", telephone[key].name); break;
        case 2:
            printf("Update birth: "); scanf("%s", telephone[key].birth); break;
        case 3:
            printf("Update number: "); scanf("%s", telephone[key].number); break;

        default: printf("Error\n"); break;
        }

        printf("%d %s %s %s\n\n",
            telephone[key].id, telephone[key].name, telephone[key].birth, telephone[key].number);
    }
}

void Delete() {
    int Delete, key;
    int delete_id;
    char delete_name[31], delete_birth[15], delete_number[15];
    bool delete_flag = false;

    printf("How to search(1: ID 2: name 3: birth 4: number : ");
    scanf("%d", &Delete);
    switch (Delete) {
    case 1:
        printf("id: "); scanf("%d", &delete_id); getchar();
        for (i = 0; i < num; i++) {
            if (i == delete_id) {
                key = i;
                delete_flag = true;
            }
        }
        if (delete_flag == false)
            printf("Not Exist The id.\n\n");
        break;

    case 2:
        printf("name: "); scanf("%s", delete_name); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(delete_name, telephone[i].name) == 0) {
                key = i;
                delete_flag = true;
            }
        }
        if (delete_flag == false) printf("Not Exists The name.\n\n"); break;

    case 3:
        printf("birth: "); scanf("%s", delete_birth); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(delete_birth, telephone[i].birth) == 0) {
                key = i;
                delete_flag = true;
            }
        }
        if (delete_flag == false)
            printf("Not Exists The birth.\n\n");
        break;

    case 4:
        printf("number: "); scanf("%s", delete_number); getchar();
        for (i = 0; i < num; i++) {
            if (strcmp(delete_number, telephone[i].number) == 0) {
                key = i;
                delete_flag = true;
            }
        }
        if (delete_flag == false)
            printf("Not Exist Number.\n\n");
        break;

    default:
        printf("ERROR\n\n"); getchar(); break;
    }
    if (delete_flag == false) {}
    else {
        printf("Delete\n");
        for (i = key; i < num; i++) {
            telephone[i].id = telephone[i + 1].id;
            strcpy(telephone[i].name, telephone[i + 1].name);
            strcpy(telephone[i].birth, telephone[i + 1].birth);
            strcpy(telephone[i].number, telephone[i + 1].number);
        }
        num--;
    }
}

void Print() {
    for (i = 0; i < num; i++)
        printf("%d %s %s %s\n",
            telephone[i].id, telephone[i].name, telephone[i].birth, telephone[i].number);
    printf("\n");
}

void Function() {
    int n;

    do {
        printf("Input number\n");
        printf("1 : Register 2 : Search 3: Update 4: Delete 5: Print\n");
        printf("6: Write the file(.txt format): ");
        scanf("%d", &n); getchar();

        switch (n) {
        case 1:
            printf("Register\n");
            Register(); break;

        case 2:
            printf("Search\n");
            Search(); break;

        case 3:
            printf("Update\n");
            Update();  break;

        case 4:
            printf("Delete\n");
            Delete(); break;

        case 5:
            printf("Print.\n");
            Print();  break;

        case 6:
            printf("Reading File(.txt).\n");
            Reading(); break;

        }
    } while (1 <= n && n <= 6);
}

int main(void) {

    Download();
    Function();
    Reading();

    return 0;
}