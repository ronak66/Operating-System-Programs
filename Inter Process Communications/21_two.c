#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	char buff[100];
	int fd_read = open("fifo_one_to_two",O_RDONLY);
	read(fd_read,buff,sizeof(buff));
	printf("From 2: One to two recieved: %s\n",buff);

    printf("From 2: Two to one transmited: ");
	scanf("%s",buff);
	int ret = mknod("fifo_two_to_one",S_IFIFO | 0744,0);
	int fd = open("fifo_two_to_one",O_WRONLY);
	write(fd,buff,sizeof(buff));	


    return 0;
}

