
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>

int main(void){

    fd_set rfds;
    int fd = open("fifo",O_RDONLY);

    // Clear the rfds set
    FD_ZERO(&rfds); 
     // Set the rfds to 0
    FD_SET(fd, &rfds);
    struct timeval tv;
    tv.tv_sec = 10; // wait time
    tv.tv_usec = 0;
    
    int ret = select(fd+1, &rfds, NULL, NULL, &tv);
    
    if(ret){
        printf("Data is available now.\n");
        char buff[100];
        read(fd,buff,sizeof(buff));
        printf("%s\n",buff);
    }
    else{
        printf("Data is not available within 10 seconds");
        exit(0); 
    }	
}	
