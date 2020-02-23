#include<stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main(){
    int pid = fork();
    if(pid == 0){
        sleep(1);
        printf("Child Process\n");
    }
    else if(pid > 0){
        printf("Parent process\n");
    }
    return 0;
}