
#include<unistd.h>
#include <stdio.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include<arpa/inet.h>


int main(){
	struct sockaddr_in serv_addr,addr;
	int socket_fd = socket(AF_INET,SOCK_STREAM,0);
		
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(5555);
	bind(socket_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	
	listen(socket_fd,5);
    char buff1[100],buff2[100];

	while(1){
		int addrlen = sizeof(addr);	
		int fd = accept(socket_fd,(struct sockaddr *)&addr,&addrlen);
        if(!fork()){
            int len = read(fd,buff1,sizeof(buff1));		
            write(1,"Message1 from client: ",sizeof("Message1 from client: "));
            write(1,buff1,len);    
            write(fd,"Hello From Server\n",19);
            // getchar();
            // getchar();
        }
		else close(fd);
	}
}	
