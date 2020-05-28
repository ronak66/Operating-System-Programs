#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
	int fd = open("fifo",O_RDONLY);
	read(fd,buff,sizeof(buff));
	printf("Recieved Message: %s\n",buff);	

    return 0;
}

