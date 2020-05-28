#include<stdio.h>
#include<unistd.h>
int main(){
 
	 int pipefd[2]; //pipefd[0] - read pipefd[1] - write
	 pipe(pipefd);
	 write(pipefd[1],"OS Assignment\n",100);

     char read_input[100];
	 read(pipefd[0],&read_input,sizeof(read_input));
	 printf("%s",read_input);


}
