#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){

	int pipefd[2];
	pipe(pipefd);
    int pid = fork();
	if(pid != 0){
        // close standard output
		close(1);
        // To make the fd value equall to 1 so execl dumps value here
		fcntl(pipefd[1],F_DUPFD,1); 
        // closing pipefd read
		close(pipefd[0]);
		execl("/bin/ls","ls","-l",(char *)0);
	}
	else{
        // close standard input
		close(0); 
        //To make the fd value equall to 0
		fcntl(pipefd[0],F_DUPFD,0); 
		close(pipefd[1]);
		execl("/usr/bin/wc","wc",(char *)0);
	}
}
