#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>


int main(){
    // ftok to generate unique key 
	key_t key = ftok(".", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    int msgid = msgget(key, 0666 | IPC_CREAT); 
	printf("Key = %d\n",key);
    printf("Message queue id = %d\n",msgid);
	return 0;
}