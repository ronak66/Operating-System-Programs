#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main(){
	char *buffer;
	buffer = (char*)malloc(100 * sizeof(char));
	int fd = open("1a.c",O_EXCL);
	printf("file descriptor: %d\n",fd);
	while (read(fd, buffer, 1) == 1){
		//if(*buffer == '\n') printf("ll\n");
		printf("%s",buffer);	

	}
}
