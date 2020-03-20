/* Advance Programing Shell-(p)*/
/* getenv()のtask p135-173まで*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

#define BUFSIZE 128
#define rep(i, n) for(int i = 0; i < (*n); i++)
#define rep2(j, i) for(int j = 0; j < argc[i]; j++)
#define rep3(k, n) for(int k = 0; k < n; k++)

struct process{
  int pid_id;  //proces id
  int num_cnt; //process cnt
  char *pname;  //process name
  struct process *next;
};

void Cmdline(int *pipec, int *len, bool *orflag);
void AddressCheck(int *pipec, int *len);
void Incmd(int *status, int *bg);
void Outcmd(int *processcnt, int *status, int *bg, int *getcnt, int *pipec, bool *orflag);
void show_process(struct process *p);
void free_process(struct process *p);
void handler();
void SetSignalCtrl(int signame);
void ControlBG();
void SetSignalBG(int signame);
struct process *add_process(struct process *next, pid_t pid, int id, char *name);
struct process *delete_process(struct process *p, int id);
struct process *delete_process2(struct process *p, int pid);


char *cmd, *copycmd, *pargs[BUFSIZE/4][BUFSIZE/4], *and = NULL;
int *bg2, *status2, currentpid; //reference bg and status address for signal process
struct process *top, *temp;
char *strenv, *strenv_cpy, *strenvtok[10];
int *argc;

int main(void)
{
    int pipec = 0, len = 0, status;
    int processcnt = 0;
    int bg = 0, getcnt=0;
    bool orflag = false;

    SetSignalCtrl(SIGINT);
    SetSignalBG(SIGCHLD); 
    while(1){
        bg2 = (&bg); status2 = (&status);
        if( bg == 0 ) processcnt = 0;

        /* Display prompt + classifier cmdline */
        Cmdline(&pipec, &len, &orflag);

        AddressCheck(&pipec, &len);

        /* exit, quit, fg, job command */
        Incmd(&status, &bg);

        /* others */
        Outcmd(&processcnt, &status, &bg, &getcnt, &pipec, &orflag);

        /*
        rep3(i, pipec){ rep2(j, i){ rep3(k, strlen(pargs[i][j]))
            pargs[i][j][k] = '\0';
        } }
        */
        free(cmd); free(argc);
  }
}

void Outcmd(int *processcnt, int *status, int *bg, int *getcnt, int *pipec, bool *orflag){
    bool getflag = false;
    pid_t pid;
    int pp[2] = { };

    if( (*orflag) == true ){
        if( (pid = fork()) == 0){
            rep(i, pipec){
                if( i == ((*pipec) -1) ){ execvp(pargs[0][0], pargs[0]); }
                else{
                    pipe(pp);
                    if( (pid = fork()) == 0){
                        close(pp[0]); dup2(pp[1], 1); close(pp[1]);
                    }else{
                        close(pp[1]); dup2(pp[0], 0); close(pp[0]);
                        execvp(pargs[(*pipec)-i-1][0], pargs[(*pipec)-i-1]);
                    }
                }
            }
        }
        else{ wait(NULL); }
    }
    else/*(*orflag == false)*/{
        if( (pid = fork()) < 0 ){
            perror("fork() error"); exit(-1);
        }else if( pid == 0){
            execvp(pargs[0][0], pargs[0]); exit(0);
        }else if( pid > 0 && and == NULL ){
            (currentpid) = (pid);
            waitpid(pid, status, 0);
        }else {
            (*processcnt)++; (*bg)++;
            top = add_process(top, pid, *processcnt, copycmd);
        }
    }
}

void ControlBG()
{
    int lastpid = 0;
    if( (*bg2) > 0 ){
        if( (lastpid = waitpid(-1, status2, WNOHANG)) > 0){
            temp = top;
            while( temp->pid_id != lastpid) temp = temp->next;
            if( (lastpid) == temp->pid_id)
                top = delete_process2(top, (lastpid));
            (*bg2)--;
        }
    }
}

void SetSignalBG(int signame)
{
    if(signal(signame, ControlBG) == SIG_ERR){
        perror("signal() error\n"); exit(-1);
    }
}

void handler()
{
    if( (currentpid) > 0 )
        kill((currentpid), SIGINT);
    (currentpid) = 0;

    return;
}

void SetSignalCtrl(int signame)
{
    if( signal(signame, handler) == SIG_ERR ){
        perror("signal() error\n"); exit(-1);
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
    p->pname = (char *)malloc((sizeof(char) * BUFSIZE)); strcpy(p->pname, name); free(copycmd);

    temp = next;
    if(temp == NULL)
        next = p;
    else{
        while( temp->next != NULL ) temp = temp->next;
        temp->next = p;
    }

    printf("[%d] %d\n", p->num_cnt, p->pid_id);
    return next;
}

void Incmd(int *status, int *bg)
{
    int fg;

    if( strcmp(pargs[0][0], "exit") == 0 || strcmp(pargs[0][0], "quit") == 0 ){
        printf("Goodbye\n"); free(cmd); exit(0);
    }
    else if( strcmp(pargs[0][0], "jobs") ==0 ){
        show_process(top);
    }
    else if( (strcmp(pargs[0][0], "fg") == 0 ) ){
        if( top == NULL ){  printf("Empty\n"); }
        else {
            if( pargs[0][1] != NULL ){
                fg = atoi( pargs[0][1] );
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
            else /*( pargs[0][1] == NULL )*/{
                while( temp->next != NULL ) temp = temp->next;
                waitpid(temp->pid_id, status, 0);
                top = delete_process2(top, temp->pid_id);
            }
            (*bg)--;
        }
    }
    else{ }
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
        p = temp->next; 
        free(temp);
    }
    else{
        while( temp->next->pid_id != pid ){ temp = temp->next; }
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

void Cmdline(int *pipec, int *len, bool *orflag)
{
    int s = 0;

    (*pipec) = 0; (*orflag) = false;
    cmd = (char *)malloc(sizeof(char) * BUFSIZE);
    argc = (int *)malloc(sizeof(int) * ( (*pipec)+ 1 ));
    printf("shell(p):~$ "); fgets(cmd, BUFSIZE, stdin);

    (*len) = strlen(cmd); cmd[(*len)-1] = '\0'; (*len)--;
    and = strchr(cmd, '&');

    if(and != NULL){
        copycmd = (char *)malloc(sizeof(char) * BUFSIZE); strcpy(copycmd, cmd);
    }

    pargs[0][0] = strtok(cmd, " "); argc[(*pipec)]++;
    rep(i, len){
        pargs[(*pipec)][(i+1)-s] = strtok(NULL, " "); 
        argc[(*pipec)]++;
        if( pargs[(*pipec)][(i+1)-s] == NULL ){
            argc[(*pipec)]--;
            (*pipec)++;
            break;
        }
        if( strcmp( pargs[(*pipec)][i+1-s], "|" ) == 0 ){
            pargs[(*pipec)][(i+1)-s] = NULL; //Change "|" into NULL
            s = (i + 1) + 1; (*orflag) = true;
            argc[(*pipec)]--; (*pipec)++;
            argc = (int *)realloc(argc, sizeof(int) * ( (*pipec) + 1));
        }
    }
}

void AddressCheck(int *pipec, int *len){
    rep(i, len)
        printf("cmd[%d]: %p %c\n", i, &cmd[i], cmd[i]);
    printf("\n");

    /*
    if(and != NULL){
        rep(i, len)
            printf("copycmd[%d]: %p %c\n", i, &copycmd[i], copycmd[i]);
        printf("\n");
    }
    */

    rep(i, pipec){ rep2(j, i){ rep3(k, strlen(pargs[i][j]))
        printf("pargs[%d][%d][%d]: %p %c\n", i, j, k, &pargs[i][j][k], pargs[i][j][k]);
      printf("\n");
    } }
}
