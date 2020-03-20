#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define BUFSIZE 128
#define rep(i, n) for(int i = 0; i < (*n); i++)

char *cmd, *pargs[BUFSIZE/4], *and = NULL;

void Cmdline(int *argc, int *len);
void AddressCheck(int *argc, int *len);
void Incmd();
void Outcmd();

int main(void)
{
    int argc = 0, len = 0;

    while(1){
        /* Display prompt + classifier cmdline */
        Cmdline(&argc, &len);

        AddressCheck(&argc, &len);
        /* exit, quit command */
        Incmd();
        /* others */
        Outcmd();

        free(cmd);
    }
    return 0;
}

void Incmd()
{
    if( strcmp(pargs[0], "exit") == 0 || strcmp(pargs[0], "quit") == 0 ){
        printf("Goodbye\n"); free(cmd); exit(0);
    }
}

void Outcmd(){
    int status;
    pid_t pid;

    if( (pid = fork()) < 0 ){
        perror("fork() error"); exit(-1);
    }else if( pid == 0 ){
        execvp(pargs[0], pargs); exit(0);
    }else if( pid > 0 && and == NULL ){
        waitpid(pid, &status, 0);
    }else{

    }
}

void Cmdline(int *argc, int *len)
{
    printf("shell(c):~$ ");
    cmd = (char *)malloc(sizeof(char) * BUFSIZE);
    fgets(cmd, BUFSIZE, stdin);
    (*len) = strlen(cmd); cmd[(*len)-1] = '\0';
    (*argc) = 0;
    and = strchr(cmd, '&');

    for(int i = 0;  i < BUFSIZE/4; i++)
        pargs[i] = (char *)malloc(sizeof(char) * BUFSIZE);

    pargs[0] = strtok(cmd, " ");
    rep(i, len-1){
        pargs[i+1] = strtok(NULL, " "); (*argc)++;
        if(pargs[i+1] == NULL) 
            break;
    }
}

void AddressCheck(int *argc, int *len)
{
    rep(i, len-1)
        printf("cmd[%d]: %p %c\n", i, &cmd[i], cmd[i]);
    printf("\n");

    for(int i = 0; i < (*argc); i++){
        for(int j = 0; j < strlen(pargs[i]); j++)
            printf("pargs[%d][%d]: %p %c\n", i, j, &pargs[i][j], pargs[i][j]);
        printf("\n");
    }
}