#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int ret = open("./test4.c",O_CREAT | O_EXCL, 0666);
	printf("file descriptor: %d\n",ret);
}

