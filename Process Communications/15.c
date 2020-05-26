#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pipefd[2];
	pipe(pipefd);
	char read_input[100];

    int pid = fork();
	if(pid != 0){
		printf("Running Parent Process\n");
        printf("Msg to be sent by parent: ");
		scanf("%s",read_input);
		write(pipefd[1],read_input,sizeof(read_input));
	}
	else{
        printf("\nRunning Child Process\n");
		read(pipefd[0],&read_input,sizeof(read_input));
        printf("Msg recieved from parent: ");
		printf("%s\n",read_input);
	}
}
