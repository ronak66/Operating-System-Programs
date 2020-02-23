#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <stdio.h>


int main(int argc, char const *argv[])
{

	int fd = open(argv[1], O_RDWR);

	struct flock lock;

	lock.l_start = 0;
	lock.l_len = 0; // Till the end of the file
	lock.l_pid = getpid();
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;

	int ticketNumber;

	fcntl(fd, F_SETLKW, &lock);

	read(fd, &ticketNumber, sizeof(int));
	printf("Ticket number: %d\n", ticketNumber);

	ticketNumber = ticketNumber + 1;

	printf("New Ticket number = %d\n", ticketNumber);

	write(fd, &ticketNumber, sizeof(int));

	lock.l_type = F_UNLCK;

	fcntl(fd, F_SETLK, &lock);

	close(fd);

	return 0;
}