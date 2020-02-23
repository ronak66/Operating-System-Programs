#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork();
    if(pid == 0){
        printf("Running Child Process:\n");
        printf("pid of child: %d\n",getpid());
        printf("pid of parent: %d\n",getppid());
    }
    else if(pid>0){
        printf("Running Parent Process:\n");
        printf("pid of parent: %d\n",getpid());
    }
    wait(0);
    return 0;
}