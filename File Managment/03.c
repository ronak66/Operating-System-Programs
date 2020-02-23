#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int ret;
	ret = creat("./test_3.txt", 0777);
	printf("file descriptor: %d\n", ret);
}
