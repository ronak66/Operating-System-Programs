#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

int main(){
	union semun arg;
	key_t key = ftok(".",'a');
	int semid=semget(key,1,IPC_CREAT | 0777);
	arg.val= 1; /*1 for binary semaphore, >1 for counting semaphore */
    semctl(semid,0,SETVAL,arg);
}
