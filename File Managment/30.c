#include<stdio.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char* argv[]){
	pid_t process_id = fork();
	// PARENT PROCESS. Need to kill it.
	if (process_id > 0){
		printf("process_id of child process %d \n", process_id);
		// return success in exit status
		exit(0);
	}
	//unmask the file mode
	umask(0);
	//set new session
	setsid();
	// Change the current working directory to root.
	chdir("/");
	// Close stdin. stdout and stderr
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	// Open a log file in write mode.
	while (1){
		//Dont block context switches, let the process sleep for some time
		sleep(1);
		printf("This is demon process");
		// Implement and call some function that does core work for this daemon.
	}
	return (0);
}
