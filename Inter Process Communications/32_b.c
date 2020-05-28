#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/shm.h>

int main() {
	key_t key = ftok(".", 'a');
	struct sembuf buf = {0, -1, 0};
	int semid = semget(key, 1, 0);
	int fd = open("ticket.txt", O_RDWR);
	char ticket[100];
	read(fd, ticket, 6);
	printf("Current ticket number : %s\n", ticket);
	printf("Enter critical section\n");
	printf("Waiting for unlock\n");

	semop(semid, &buf, 1);
	key_t shmkey = ftok(".", 'c');
	int shmid = shmget(shmkey, 1024, 0);
	char *data = shmat(shmid, 0, SHM_RDONLY);
	printf("%s\n", data);
	printf("ENTER to unlock\n");
	getchar();
	buf.sem_op = 1;
	semop(semid, &buf, 1);
	close(fd);
	return 0;
}
