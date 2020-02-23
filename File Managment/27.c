#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void){
    char *env[] = { NULL };
    char *options[] = {"-l","-R",NULL};
    execl("/bin/ls","-l","-R",NULL);
    execlp("ls","-l","-R",NULL);
    execle("/bin/ls","-l","-R",NULL, env);
    execv("/bin/ls",options);
    execvp("ls",options);
    return 0;
}