#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  /* make it a 1K shared memory segment */

int main()
{
    key_t key;
    int shmid;
    char *data;
    int mode;
    /* make the key: */
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }

    /*  create the segment: */
    if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    /* attach to the segment to get a pointer to it: */
    data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }
    printf("Enter the Message : \n");
	scanf(" %[^\n]",data);

    
    data=shmat(shmid,NULL,SHM_RDONLY);
    printf("Enter the Overwrite Message : \n");
	scanf(" %[^\n]",data);
    
    /* detach from the segment: */
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    /* remove shared memory */
    struct shmid_ds sd;
    shmctl(shmid,IPC_RMID,&sd);

    return 0;
}