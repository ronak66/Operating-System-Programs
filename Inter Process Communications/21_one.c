#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
    printf("From 1: One to two transmited: ");
	scanf("%s",buff);
	int ret = mknod("fifo_one_to_two",S_IFIFO | 0744,0);
	int fd = open("fifo_one_to_two",O_WRONLY);
	write(fd,buff,sizeof(buff));	

    int fd_read = open("fifo_two_to_one",O_RDONLY);
    read(fd_read,buff,sizeof(buff));
    printf("From 1: Two to one recieved: %s\n",buff);

    return 0;
	
}

