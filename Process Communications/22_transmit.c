#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
    printf("Message to be transmited: ");
	scanf("%s",buff);
	int ret = mknod("fifo",S_IFIFO | 0744,0);
	int fd = open("fifo",O_WRONLY);
	write(fd,buff,sizeof(buff));	

    return 0;
	
}