#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void parta(){
    printf("Signal SIGALRM was found\n");
}
void partb(){
    printf("Signal ITIMER_VIRTUAL was found\n");
}
void partc(){
    printf("Signal ITIMER_PROF was found\n");
}

int main(){

    struct itimerval value ;
    /* Interval for periodic timer */
    struct timeval it_value = {10,10}; //10 sec and 10 micro sec
    value.it_value = it_value;
    /* Time until next expiration */
    struct timeval it_interval = {0,0};
    value.it_interval = it_interval;
    
    int ret;
    signal(SIGALRM,parta);
    ret = setitimer(ITIMER_REAL, &value, 0);
    sleep(15);

    // signal(SIGVTALRM,partb);
    // ret = setitimer(ITIMER_VIRTUAL, &value, 0);
    // sleep(15);

    // signal(SIGPROF,partc);
    // ret = setitimer(ITIMER_PROF, &value, 0);
    // sleep(15);
    
    return 0;
}
