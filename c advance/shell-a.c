#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define BUFSIZE 128

int main(void){
    char *cmd, *pargs[2];
    int len, status, check;
    pid_t pid;

    while(1){
        cmd = (char *)malloc(sizeof(char) * BUFSIZE);

        printf("shell(a):~$ "); fgets(cmd, BUFSIZE, stdin);
        len = strlen(cmd); 
        cmd[len-1] = '\0';

        pargs[0] = cmd; 
        pargs[1] = NULL;

        if( strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0 ){
            printf("Goodbye\n"); 
            free(cmd); 
            break;
        }

        if( (pid = fork()) < 0 ){
            perror("fork() error"); exit(-1);
        }else if( pid == 0 ){
            execvp(pargs[0], pargs); exit(0);
        }

    wait(&status);

    free(cmd);
  }
  return 0;
}
