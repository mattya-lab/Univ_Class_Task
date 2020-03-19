/* Advance Programing Shell-(b)*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define BUFSIZE 128
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    char *cmd, *pargs[BUFSIZE/4];
    int argc=0, len, status;
    pid_t pid;

    while(1){
        cmd = (char *)malloc(sizeof(char) * BUFSIZE);

        rep(i, BUFSIZE/4)
            pargs[i] = (char *)malloc(sizeof(char) * BUFSIZE);


        printf("shell(b):~$ "); fgets(cmd, BUFSIZE, stdin);
        len = strlen(cmd); cmd[len-1] = '\0';

        pargs[0] = strtok(cmd, " ");
        printf("argc: %d, pargs[0] : %s\n", argc, pargs[0]);

        rep(i, len-1){
            pargs[i+1] = strtok(NULL, " "); argc++;
            if(pargs[i+1] == NULL) 
                break;
        }

        rep(i, len-1)
            printf("cmd[%d]: %p %c\n", i, &cmd[i], cmd[i]);

        if( strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0 ){
            printf("Goodbye\n"); free(cmd); break;
        }

        rep(i, argc)
            rep(j, strlen(pargs[i]))
                printf("pargs[%d][%d]: %p %c\n", i, j, &pargs[i][j], pargs[i][j]);

        if( (pid = fork()) < 0 ){
            perror("fork() error"); exit(-1);
        }else if( pid == 0 ){
            execvp(pargs[0], pargs); exit(0);
        }

        wait(&status);

        free(cmd);
        argc = 0;
    }
    return 0;
}
