#include <fcntl.h>

#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, char const *argv[]){


    // Read Lock
	int fd = open(argv[1], O_RDONLY);

	struct flock lock;

	lock.l_start = 0;
	lock.l_len = 0; // Till the end of the file
	lock.l_pid = getpid();
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;

	fcntl(fd, F_SETLKW, &lock);
	
	printf("Press Enter to unlock read lock\n");
	getchar();

	printf("Unlocked\n");

	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	close(fd);


    // Write lock
    lock.l_type = F_WRLCK;
    fcntl(fd, F_SETLKW, &lock);
	
	printf("Press Enter to unlock to write lock\n");
	getchar();

	printf("Unlocked\n");

	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	close(fd);
	return 0;
}