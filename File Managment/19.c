#include<stdio.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    clock_t start, end;
    start = clock();
    int pid = getpid();
    end = clock();
    printf("pid of process: %d\n",pid);
    printf("time taken to execute pid(): %f seconds\n",(end-start)/(double)(CLOCKS_PER_SEC));
    return 0;
}