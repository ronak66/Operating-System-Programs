#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

int main(){
	int key, semid;
	key=ftok(".",'a');
	semid=semget(key,1,0);
	semctl(semid,0,IPC_RMID,0);
}
