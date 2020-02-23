#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

int main(int argc, char const *argv[]){

	int fd_1 = open(argv[1], O_CREAT | O_RDWR, 0777);
	int fd_dup = dup(fd_1);
    int fd_dup2 = dup2(fd_1, 10);
    int fd_fcntl = fcntl(fd_1, F_DUPFD);


	printf("File descriptor: %d \nfd_dup file descriptor: %d\n", fd_1, fd_dup);
    printf("fd_dup2 File descriptor: %d \nfd_fcntl Duplicate file descriptor: %d\n", fd_dup2, fd_fcntl);

	write(fd_1, "Append using fd_1", 20); // 8 including the /n
	write(fd_dup, "Append using fd_dup", 20);
	write(fd_dup2, "Append using fd_dup2", 20);
    write(fd_fcntl, "Append using fd_fcntl", 20);


	return 0;
}