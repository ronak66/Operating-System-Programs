#include <unistd.h>
#include<stdio.h>	

int main()
{
	long PIPE_BUF,OPEN_MAX;
    //The  maximum  number  of  bytes that can be written atomically to a pipe of FIFO
	long int size_of_pipe = pathconf(".",_PC_PIPE_BUF);
    // The maximum number of files that a process can have open at any time
	long int max_num_files = sysconf(_SC_OPEN_MAX);
	printf("Maximum Size that can be written to a pipe = %ld\n",size_of_pipe);
    printf("Maximum no. of files that a process can open = %ld\n",max_num_files);
	return 0;
}
