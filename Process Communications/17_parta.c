#include<stdio.h>
#include<unistd.h>

int main(){

	int pipefd[2];
	pipe(pipefd);
    int pid = fork();
	if(pid != 0){
        // close standard output
		close(1);
        // To make the fd value equall to 1 so execl dumps value here as dup assigns least value
		dup(pipefd[1]); 
        // closing pipefd read
		close(pipefd[0]);
		execl("/bin/ls","ls","-l",(char *)0);
	}
	else{
        // close standard input
		close(0); 
        //To make the fd value equall to 0 as dup assigns least value
		dup(pipefd[0]); 
		close(pipefd[1]);
		execl("/usr/bin/wc","wc",(char *)0);
	}
}
