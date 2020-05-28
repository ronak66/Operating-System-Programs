#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>


int main(){
	int shmid;
	char *data;
	key_t key;
	key=ftok(".",'c');	//returns unique key value
	shmid=shmget(key,1024,IPC_CREAT|IPC_EXCL|0744);	//shared memory id
	data=shmat(shmid,0,0);

	printf("Enter the text : \n");
	scanf(" %[^\n]",data);
	return 0;
}

//$ipcs -m :: to check shared memory
//$ipcrm -m <shmid> :: remove shared memory id
