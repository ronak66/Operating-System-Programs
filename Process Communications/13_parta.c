#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void my_handler (int sig) {
    printf("Caught SIGSTOP\n");
}

int main ( void ) {

    int pid = fork();
    signal (SIGSTOP, my_handler);
	if(pid != 0){
        printf("Running parent Process:\n");		
	}
	else{
        printf("%d\n",getpid());
        sleep(50);
        printf("Running child Process\n");
	}
    // printf("%d\n",getpid());
    // getchar();
    sleep(15);

    return 0;

}



