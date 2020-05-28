#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>


int main(){
	struct msqid_ds buf;
	key_t key = ftok(".",'a');
	int msgid = msgget(key,0);
	msgctl(msgid,IPC_RMID,&buf);
}
