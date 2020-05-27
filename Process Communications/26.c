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
	printf("Enter a message type: ");
	scanf("%ld",&queue.mtype);
	printf("Enter a message text: ");
	scanf(" %s", queue.mtext);
	int size = strlen(queue.mtext);
	printf("%d\n",size);
	msgsnd(msgid,&queue,size+1,0);
	getchar();
	getchar();
	getchar();	
}
