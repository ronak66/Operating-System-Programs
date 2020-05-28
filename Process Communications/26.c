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
	int msgid = msgget(key,0666 | IPC_CREAT);
	printf("Enter a message type: ");
	scanf("%ld",&queue.mtype);
	printf("Enter a message text: ");
	scanf(" %s", queue.mtext);
	int size = strlen(queue.mtext);
	printf("%d\n",size);
	int ret = msgsnd(msgid,&queue,size+1,0);
	printf("Msg queue status: %d\n",ret);
	if(ret == -1) perror("msgsnd");
	getchar();
	getchar();
	getchar();	
}
