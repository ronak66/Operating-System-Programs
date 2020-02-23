#include<stdio.h>
#include<fcntl.h>

int main(int argc, char const *argv[]){
    int fd_1 = open(argv[1], O_RDWR);

	int fcn = fcntl(fd_1, F_GETFL);

	printf("mode: %d\n", fcn);

    return 0;
}