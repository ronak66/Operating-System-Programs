
#include<unistd.h>
#include <stdio.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include<arpa/inet.h>


int main(){

	struct sockaddr_in serv_addr;
	int socket_fd = socket(AF_INET,SOCK_STREAM,0);
	
	char buff[25],username[25],password[25];	

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(5555);

	connect(socket_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	printf("Client msg to server: Hello i am client\n");
	write(socket_fd,"Hello i am client\n",sizeof("Hello i am client\n"));
	printf("Connecting ................\n");
	int len = read(socket_fd,buff,sizeof(buff));				
	write(1,buff,len);	

    close(socket_fd);
}


