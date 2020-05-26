#include<stdio.h>
#include<unistd.h>
int main(){
	int pipefd1[2],pipefd2[2];
	pipe(pipefd1);
	pipe(pipefd2);
	char read_input[100];
    int pid = fork();
    
	if(pid != 0){
        printf("Running Parent Process\n");
        printf("Msg to be sent by parent to child: ");
		scanf("%s",read_input);
		write(pipefd1[1],read_input,sizeof(read_input));
		read(pipefd2[0],&read_input,sizeof(read_input));
        printf("Msg recieved from child to parent: %s\n",read_input);
	}
	else{
		read(pipefd1[0],&read_input,sizeof(read_input));
        printf("Msg recieved from parent to child: %s\n",read_input);
		printf("Msg to be sent by child to parent: ");
		scanf("%s",read_input);
		write(pipefd2[1],read_input,sizeof(read_input));
	}
}
