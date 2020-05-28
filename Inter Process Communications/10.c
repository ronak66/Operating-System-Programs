#include <signal.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>

void sig_handler (int sig) {
    if(sig == SIGSEGV) printf ("Recieved SIGSEGV\n");
    if(sig == SIGINT) printf ("Recieved SIGINT\n");
    if(sig == SIGFPE) printf ("Recieved SIGFPE\n");
}

int main ( void ) {

    struct sigaction sig_action;

    sig_action.sa_handler = sig_handler;
    sigaction (SIGSEGV, &sig_action, NULL);
    // sigaction (SIGINT, &sig_action, NULL);
    // sigaction (SIGFPE, &sig_action, NULL);

    raise(SIGSEGV);
    sleep(5);
	
    return 0;
}



