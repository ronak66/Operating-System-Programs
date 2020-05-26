#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

/*
Part A:
mknod myfifo p

Part B:
mkfifo myfifo

Part C:
strace -c mknod
strace -c mkfifo
*/

int main(){
	int fd=mknod("fifo",S_IFIFO,0);
	printf("Return Status of mknod: %d\n",fd);
    
    fd=mkfifo("myfifo",0744);
	printf("Return Status of mkfifo: %d\n",fd);
}

