#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("ticket.txt", O_WRONLY | O_CREAT);
	write(fd, "123456", 6);
	return 0;
}
