
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<pthread.h>

void *myThread(void *fd){
	int new_fd=*(int*)fd;
	char buff[50];

    int len = read(new_fd,buff,sizeof(buff));		
    write(1,"Message1 from client: ",sizeof("Message1 from client: "));
    write(1,buff,len);    
    write(new_fd,"Hello From Server\n",19);

    return 0;
}


int main(){
	struct sockaddr_in serv_addr,addr;
	int socket_fd = socket(AF_INET,SOCK_STREAM,0);
		
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(5555);
	bind(socket_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	
	listen(socket_fd,5);
    char buff1[100],buff2[100];
    pthread_t threads;
	while(1){
		int addrlen = sizeof(addr);	
		int fd = accept(socket_fd,(struct sockaddr *)&addr,&addrlen);
        pthread_create(&threads,NULL,myThread,(void*) &fd);
	}
}	
