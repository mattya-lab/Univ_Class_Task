#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/wait.h>

#define BUFSIZE 128
#define rep(i, len) for(int i = 0; i < (*len)-1; i++)

struct process{
  int pid_id;  //proces id
  int num_cnt; //process cnt
  char *pname;  //process name
  struct process *next;
};

void Cmdline(int *argc, int *len);
void AddressCheck(int *argc, int *len);
void Incmd(int *status, int *bg);
void Outcmd(int *processcnt, int *status, int *bg, int *lastpid);
void show_process(struct process *p);
void free_process(struct process *p);
struct process *add_process(struct process *next, pid_t pid, int id, char *name);
struct process *delete_process(struct process *p, int id);
struct process *delete_process2(struct process *p, int pid);


char *cmd, *copycmd, *pargs[BUFSIZE/4], *and = NULL;
struct process *top, *temp;

int main(void)
{
    int argc = 0, len = 0, status;
    int processcnt = 0;
    int bg = 0, lastpid = 0;

    if( (top = (struct process *)malloc(sizeof(struct process)) ) == NULL){
        perror("malloc() error\n"); exit(-1);
    }

    top = NULL;

    while(1){
        /* Display prompt + classifier cmdline */
        Cmdline(&argc, &len);

        //AddressCheck(&argc, &len);

        /* exit, quit, fg, job command */
        Incmd(&status, &bg);

        /* others */
        Outcmd(&processcnt, &status, &bg, &lastpid);
    }
}

void Incmd(int *status, int *bg)
{
    int fg;

    if( strcmp(pargs[0], "exit") == 0 || strcmp(pargs[0], "quit") == 0 ){
      printf("Goodbye\n"); free(cmd); exit(0);
    }
    else if( strcmp(pargs[0], "jobs") ==0 ){
        show_process(top);
    }
    else if( (strcmp(pargs[0], "fg") == 0 ) ){
        if( top == NULL ){  printf("Empty\n"); }
        else {
            if( pargs[1] != NULL ){
                fg = atoi( pargs[1] );
                temp = top;
                while( temp->num_cnt != fg){
                    if( temp->next == NULL ){ printf("No Process\n"); break; }
                    else{ temp = temp->next; }
                }
                if( temp->num_cnt == fg ){
                    waitpid(temp->pid_id, status, 0);
                    top = delete_process(top, fg);
                }
            }
            else /* ( pargs[1] == NULL ) */{
                while( temp->next != NULL ) temp = temp->next;
                waitpid(temp->pid_id, status, 0);
                top = delete_process2(top, temp->pid_id);
            }
            (*bg)--;
        }
    }
    else{ }
}

void Outcmd(int *processcnt, int *status, int *bg, int *lastpid){
    pid_t pid;

    if( (pid = fork()) < 0 ){
        perror("fork() error"); exit(-1);
    }else if( pid == 0 ){
        execvp(pargs[0], pargs); exit(0);
    }else if( pid > 0 && and == NULL ){
        waitpid(pid, status, 0);
    }else/*(pid > 0 && and == "&")*/{
        (*processcnt)++; (*bg)++;
        top = add_process(top, pid, *processcnt, copycmd);
    }

    if( ( (*lastpid) = waitpid(-1, status, WNOHANG) ) > 0 ){
        temp = top;
        while( temp->pid_id != (*lastpid) ) temp = temp->next;
        if( (*lastpid) == temp->pid_id){
            top = delete_process2(top, (*lastpid));
        }
        (*bg)--;
    }
}

struct process *add_process(struct process *next, pid_t pid, int id, char *name)
{
    struct process *p;

    if( (p = (struct process *)malloc(sizeof(struct process))) == NULL){
        perror("malloc() error\n"); exit(-1);
    }
    p->pid_id = pid;
    p->num_cnt = id;
    p->pname = (char *)malloc((sizeof(char) * BUFSIZE)); 
    strcpy(p->pname, name); 
    free(copycmd);

    temp = next;
    if(temp == NULL)
        next = p;
    else{
        while( temp->next != NULL )
            temp = temp->next;
        temp->next = p;
    }

    printf("[%d] %d\n", p->num_cnt, p->pid_id);
    return next;
}

struct process *delete_process(struct process *p, int id)
{
    struct process *temp2;
    temp = p;
    if( temp->num_cnt == id ){
        p = temp->next; free(temp);
    }
    else{
        while( temp->next->num_cnt != id ){
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return p;
}

struct process *delete_process2(struct process *p, int pid)
{
    struct process *temp2;
    temp = p;
    if( temp->pid_id == pid ){
        p = temp->next; free(temp);
    }
    else{
        while( temp->next->pid_id != pid ){
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return p;
}

void show_process(struct process *p)
{
    if(p == NULL) printf("No Process\n");
    while(p != NULL){
        printf("[%d] %s\n", p->num_cnt, p->pname);
        p = p->next;
    }
    printf("\n");
}

void free_process(struct process *p)
{
    struct process *p2;

    while(p != NULL){
        p2 = p->next;
        free(p);
        p = p2;
    }
}

void Cmdline(int *argc, int *len)
{
    cmd = (char *)malloc(sizeof(char) * BUFSIZE);
    printf("shell(d):~$ "); fgets(cmd, BUFSIZE, stdin);

    (*argc) = 0;
    (*len) = strlen(cmd); cmd[(*len)-1] = '\0';
    and = strchr(cmd, '&');

    if(and != NULL){
        copycmd = (char *)malloc(sizeof(char) * BUFSIZE); strcpy(copycmd, cmd);
    }

    pargs[0] = strtok(cmd, " ");
    rep(i, len){
        pargs[i+1] = strtok(NULL, " "); (*argc)++;
        if(pargs[i+1] == NULL) break;
    }
}

void AddressCheck(int *argc, int *len)
{
    rep(i, len)
        printf("cmd[%d]: %p %c\n", i, &cmd[i], cmd[i]);
    printf("\n");

    if(and != NULL){
        rep(i, len)
            printf("copycmd[%d]: %p %c\n", i, &copycmd[i], copycmd[i]);
        printf("\n");
    }

    for(int i = 0; i < (*argc); i++){
        for(int j = 0; j < strlen(pargs[i]); j++)
            printf("pargs[%d][%d]: %p %c\n", i, j, &pargs[i][j], pargs[i][j]);
        printf("\n");
    }
}