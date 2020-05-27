// do gcc -pthread
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h>

void *myThread(void *vargp) 
{ 
    sleep(1); 
    printf("Printing this from Thread id: %ld \n",pthread_self()); 
    return NULL; 
} 
int main(){
	pthread_t thread_id;
	for(int i=0;i<3;i++){
	    int err = pthread_create(&thread_id, NULL, myThread, NULL); 
        if (err != 0)
            printf("can't create thread\n");
        else
            printf("Thread created successfully\n");
        printf("In main thread id = %ld\n", thread_id);
    }
	pthread_exit(NULL);
	return 0;
	
}
