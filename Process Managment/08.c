#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    char *file = *++argv;
    execv(file, ++argv);
}