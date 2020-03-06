#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int mod, num/* total_num */, i;
char name[32]/* Serch Insert Delete */, gen;
double eng, math;
bool flag = false, seed[5];

struct student {
    char name[32];
    char gen;
    double eng, math;
};
struct node {
    struct node* prev;
    struct student student;
    struct node* next;
};

struct student student_data[20];
struct node* table[5];

void initialize() {
    for (i = 0; i < 5; i++) {
        table[i] = NULL;
        seed[i] = false;
    }
}

void insert(struct node** table) {
    struct node* top;
    char str_eng[3], str_math[3];

    top = (struct node*)malloc(sizeof(struct node));
    if (flag == false) {
        mod = student_data[i].name[0] % 5;
        strcpy(top->student.name, student_data[i].name);
        top->student.gen = student_data[i].gen;
        top->student.eng = student_data[i].eng;
        top->student.math = student_data[i].math;
    }
    else/* (flag == true) */ {
        mod = *name % 5;
        printf("Gen: Eng: Math: ");  scanf("%c %s %s", &gen, str_eng, str_math);
        eng = atof(str_eng);
        math = atof(str_math); getchar();

        strcpy(top->student.name, name);
        top->student.gen = gen;
        top->student.eng = eng;
        top->student.math = math;
    }

    if (seed[mod] == false) {
        top->prev = NULL; top->next = NULL;
        table[mod] = top;
        seed[mod] = true;
    }
    else/* (seed[mod] == true) */ {
        top->prev = NULL;
        top->next = table[mod];
        table[mod]->prev = top;
        table[mod] = top;
    }
}

void print_hash(struct node** table) {
    struct node* clone;
    for (i = 0; i < 5; i++) {
        clone = table[i];
        printf("%d ", i);
        while (clone != NULL) {
            printf("%s ", clone->student.name);
            clone = clone->next;
        }
        printf("\n");
    }
}

void download() {
    FILE* fp;
    i = 0;

    if ((fp = fopen("Seiseki.dat", "r")) == NULL) {
        printf("Don't Open");
        fclose(fp);
    }
    else {
        while (fscanf(fp, "%s %c %lf %lf",
            student_data[i].name, &student_data[i].gen,
            &student_data[i].eng, &student_data[i].math) == 4) {
            i++; num = i;
        }
        fclose(fp);
    }
}

void loading() {
    for (i = 0; i < num; i++)
        insert(table);

    flag = true;
    print_hash(table);
}

struct node* member(struct node** table, char* name) {
    struct node* clone;
    mod = *name % 5;
    clone = table[mod];
    while (clone != NULL) {
        if (strcmp(clone->student.name, name) == 0)
            return clone;
        clone = clone->next;
    }
    return NULL;
}

void del(struct node** table, char* name) {
    struct node* clone;
    mod = (*name) % 5;
    clone = table[mod];
    while (clone != NULL) {
        if (strcmp(clone->student.name, name) == 0) {
            if (clone->prev == NULL && clone->next == NULL) {
                seed[mod] = false;
            }
            else if (clone->prev == NULL) {
                clone->next->prev = NULL;
                table[mod] = clone->next;
                clone->next = NULL;
            }
            else if (clone->next == NULL) {
                clone->prev->next = NULL;
                clone->prev = NULL;
            }
            else {
                clone->prev->next = clone->next;
                clone->next->prev = clone->prev;
            }
            getchar();
            free(clone);
            break;
        }
        clone = clone->next;
    }
}

void Hash() {
    int i, n;
    while (1) {
        printf("0: Print, 1: Search, 2: Insert, 3:Delete, Other: Exit :");
        scanf("%d", &n); getchar();

        switch (n) {
        case 0:
            print_hash(table); break;

        case 1:
            printf("Serch Name: "); scanf("%s", name);
            if (member(table, name) != NULL) printf("Exist Key\n");
            else/*(member(table, name)==NULL) */printf("Not Exists Key\n");
            break;

        case 2:
            printf("Insert Name: "); scanf("%s", name);
            if (member(table, name) == NULL) {
                insert(table);
                print_hash(table); getchar();
            }
            else/* (member(table, name) != NULL) */ printf("Error!!\n");
            getchar();  break;

        case 3:
            printf("Delete Name: "); scanf("%s", name);
            if (member(table, name) != NULL) {
                del(table, name); print_hash(table);
            }
            else/* (member(table, name) == NULL) */ printf("Error\n");
            break;

        default:  break;
        }
        if (n < 0 || 3 < n)
            break;
    }

    for (i = 0; i < 5; i++)
        free(table[i]);

    printf("Exit\n");
}

int main(void) {

    initialize();
    download();
    loading();
    Hash();

    return 0;
}