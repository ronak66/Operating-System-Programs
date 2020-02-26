#include<stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main(){
    pid_t pid = fork();
    if(pid > 0){
        printf("parent id: %d\n",pid);
        sleep(50);
    }
    else{
        printf("child id: %d\n",pid);
        exit(0);
    }
    return 0;
}