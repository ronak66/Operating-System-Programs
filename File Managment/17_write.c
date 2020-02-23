#include <fcntl.h>

#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd = open(argv[1], O_WRONLY);

	int ticketNumber = 10;

	write(fd, &ticketNumber, sizeof(int));

	return 0;
}
