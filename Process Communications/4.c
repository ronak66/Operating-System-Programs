# include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>

#include<sys/time.h>

unsigned long long rdtscl(void)
{
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));                        
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );  
}

int main(){
	long long int start_time,end_time;
	double total_time;
	start_time=rdtscl();    
	for(int i=0;i<100;i++)  getppid();
	end_time=rdtscl();
	total_time=(end_time-start_time);
	printf("Time Taken = %lf ticks\n",total_time);
}
