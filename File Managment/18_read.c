#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int setRecordLock(int fd, struct flock * lock, int recordNumber, short type) {
	lock->l_start = (recordNumber - 1) * sizeof(int);
	lock->l_len = sizeof(int);
	lock->l_pid = getpid();
	lock->l_type = type;
	lock->l_whence = SEEK_SET;
	return fcntl(fd, F_SETLKW, lock);
}

int main(int argc, char const *argv[])
{

	struct flock lock;

	int fd = open(argv[1], O_RDWR);

	printf("Record Number: \n");
	int recordNumber;
	scanf("%d", &recordNumber);

	int offset = (recordNumber - 1) * sizeof(int);


	// Locking record
	printf("Setting lock.\n\n");
	setRecordLock(fd, &lock, recordNumber, F_WRLCK);

	int ticketNumber;
	
	pread(fd, &ticketNumber, sizeof(int), offset);

	printf("current ticket number = %d\n", ticketNumber);

	ticketNumber = ticketNumber + 1;

	pwrite(fd, &ticketNumber, sizeof(int), offset);

	printf("updated ticketNumber = %d\n", ticketNumber);

	printf("\nEnter to unlock\n");
	getchar();

	setRecordLock(fd, &lock, recordNumber, F_UNLCK);
	printf("Unlocked\n");

	close(fd);

	return 0;
}