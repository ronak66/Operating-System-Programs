#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>


int main(){
	//char a[1000];
	char *a;
	a = (char*)malloc(100 * sizeof(char));
	int file1_fd;
	file1_fd = open("1a.c",O_EXCL);
	printf("%d\n",file1_fd);
	ssize_t size1 = read(file1_fd,a,1000);
	printf("%ld\n",size1);
	int file2_fd = open("test.c",O_WRONLY, 0777);
	ssize_t size2 = write(file2_fd, a, size1);
	printf("%s\n",a);
	return 0;

}
