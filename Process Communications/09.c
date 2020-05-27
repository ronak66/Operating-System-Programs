#include<stdio.h>
#include<signal.h>
#include<sys/time.h>
#include<unistd.h>

int main ( void ) {

    signal (SIGINT, SIG_IGN);
    sleep(5);

    signal (SIGINT, SIG_DFL);
    sleep(5);
    return 0;

}