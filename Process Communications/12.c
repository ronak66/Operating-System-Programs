#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid = fork();
	if(pid != 0){
        printf("Running parent Process:\n");
		kill(getppid(),SIGKILL);		
		printf("Parent process is killed\n");
	}
	else{
        // wait(0);
        printf("Running child Process\n");
	}
}
