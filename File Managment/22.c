#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
    int pid = fork();
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0777);
    if(pid == 0){
        printf("Running child Process:\n");
        write(fd, "child process writing\n", sizeof("child process writing\n"));
    }
    else if(pid > 0){
        printf("Running parent Process:\n");
        write(fd, "parent process writing\n", sizeof("parent process writing\n"));
    }
    wait(0);
    return 0;
}