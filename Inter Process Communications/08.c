#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

void sig_handler (int sig) {
    if(sig == SIGSEGV)  printf("Caught SIGSEGV\n");
    if(sig == SIGINT)  printf("Caught SIGINT\n");
    if(sig == SIGFPE)  printf("Caught SIGFPE\n");
    if(sig == SIGALRM)  printf("Caught SIGALRM\n");
    if(sig == SIGVTALRM)  printf("Caught SIGVTALRM\n");
    if(sig == SIGPROF)  printf("Caught SIGPROF\n");
}

int main ( void ) {

    

    // Part A
    signal (SIGINT, sig_handler); //ctrl + c to invoke SIGINT
    sleep(5);

    signal (SIGSEGV, sig_handler); //Invoked by kill -11 <pid>
    sleep(5);

    signal (SIGFPE, sig_handler); //Invoked by kill -8 <pid>
    sleep(5);

    raise(SIGFPE);

    struct itimerval value ;
    /* Interval for periodic timer */
    struct timeval it_value = {1,0}; //10 sec and 10 micro sec
    value.it_value = it_value;
    /* Time until next expiration */
    struct timeval it_interval = {0,0};
    value.it_interval = it_interval;

    int ret;
    
    ret = setitimer(ITIMER_REAL, &value, 0);
    sleep(5);

    ret = setitimer(ITIMER_VIRTUAL, &value, 0);
    sleep(5);

    ret = setitimer(ITIMER_PROF, &value, 0);
    sleep(5);
    
    return 0;

}


