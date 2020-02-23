#include<stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int pid = getpid();
    int priority = getpriority(PRIO_PROCESS,pid);
    printf("pid: %d \npriority: %d\n",pid,priority);
    int ret_nice = nice(18);
    printf("return value of nice: %d\n",ret_nice);
    int new_priority = getpriority(PRIO_PROCESS,pid);
    printf("new priority: %d\n",new_priority);
    return 0;
}