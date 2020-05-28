#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

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
	printf("Inside critical section\n");
	int fp = lseek(fd, 0, SEEK_SET);
        int ticket_number = atoi(ticket);
        ticket_number = ticket_number + 1;
        char new_ticket_number[100];
    	sprintf(new_ticket_number, "%d", ticket_number);
    	int num = write(fd, new_ticket_number, 6);
	printf("ENTER to unlock\n");
	getchar();
	buf.sem_op = 1;
	semop(semid, &buf, 1);
	close(fd);
	return 0;
}
