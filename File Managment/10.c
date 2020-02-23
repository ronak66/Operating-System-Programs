#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd = open(argv[1], O_RDWR);
	printf("file descriptor: %d\n", fd);

	write(fd, "abcdefghij", 10);

	printf("%d\n", (int) lseek(fd, 10, SEEK_CUR));

	write(fd, "mnopqrstuv", 10);

	close(fd);

	return 0;
}