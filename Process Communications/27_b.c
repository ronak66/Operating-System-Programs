#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main(){
    struct msgbuf {
        long mtype;       /* message type, must be > 0 */
        char mtext[100];    /* message data */
    } queue;
	key_t key = ftok(".",'a');
	int msgid = msgget(key,0);
	printf("Msg recceive type: ");
	scanf("%ld",&queue.mtype);
	int ret = msgrcv(msgid,&queue,sizeof(queue.mtext),queue.mtype,IPC_NOWAIT|MSG_NOERROR);
	printf("Message type : %ld\n", queue.mtype);
	printf("Message text : %s\n",queue.mtext);
}
