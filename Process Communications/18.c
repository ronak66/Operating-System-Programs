#include<stdio.h>
#include<unistd.h>

int main(){

	int pipefd1[2],pipefd2[2];
	pipe(pipefd1);
    pipe(pipefd2);

	if(!fork()){
		close(1);
		dup2(pipefd1[1],1);
		close (pipefd2[0]); 
		close(pipefd2[1]);
		close(pipefd1[0]);
		execl("/bin/ls","ls","-l",(char *)0);
	}
	else if(!fork()){
        close(0);
		dup2(pipefd1[0],0);
		close(pipefd1[1]);
        close(1);
		dup2(pipefd2[1],1);
		close (pipefd2[0]);
		execl("/bin/grep","grep","^d",(char *)0);
	}
	else{
        close(0);
		dup2(pipefd2[0],0);
		close(pipefd2[1]);
		close(pipefd1[1]);
		close(pipefd1[0]);
		execl("/usr/bin/wc","wc",(char *)0);
	}

    return 0;
}
