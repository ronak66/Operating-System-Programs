//fd[1] out write
//fd[0] in read
// writing from child to parent
#include<stdio.h>
#include<unistd.h>

int main(){
	int fd1[2],fd2[2];
	pipe(fd1);pipe(fd2);
	char buff[6];
	if(!fork()){
		//close(1);  // close standard output is not necessary since we are creating dup2 file with mentioned fd value 1 which automaticall replaces this stand out
		printf("%d\n",getppid());
		dup2(fd1[1],1);
		close (fd2[0]); 
		close(fd2[1]);
		close(fd1[0]);
		execl("/bin/ls","ls","-l",(char *)0);
	}
	else if(!fork()){
		printf("%d\n",getppid());
		dup2(fd1[0],0);
		close(fd1[1]);
		dup2(fd2[1],1); // dupilicating fd
		close (fd2[0]); // closing fd read
		execl("/bin/grep","grep","^d",(char *)0);
	}
	else{
		//close(0);
		dup2(fd2[0],0);
		close(fd2[1]);
		close(fd1[1]);
		close(fd1[0]);
		execl("/usr/bin/wc","wc",(char *)0);
	}
}
