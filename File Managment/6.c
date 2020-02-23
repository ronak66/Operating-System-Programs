#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	char a[100];
	printf("file descriptor for STDIN: %d\n",STDIN_FILENO);
	ssize_t ret_in = read(0, a, 100);
	printf("read status: %d\n",ret_in);
	printf("read data: %s\n",a);
	ssize_t ret_out = write(1, a, ret_in);
	printf("write status: %d\n",ret_out);
	return 0;
}
