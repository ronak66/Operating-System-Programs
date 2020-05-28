#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<unistd.h>


int main(){
	struct rlimit rlim,rlim_get; 
	rlim.rlim_cur=10;
	rlim.rlim_max=10;

    int ret_get=getrlimit(RLIMIT_CPU, &rlim_get);
    printf("Return status of getrlimit for RLIMIT_CPU resource = %d\n",ret_get);
    printf("soft limit before = %ld\n",rlim_get.rlim_cur);
	printf("hard limit before = %ld\n",rlim_get.rlim_max);

    int ret_set=setrlimit(RLIMIT_CPU, &rlim);
    printf("Return status of setrlimit for RLIMIT_CPU resource = %d\n",ret_set);
    ret_get=getrlimit(RLIMIT_CPU, &rlim_get);
    printf("Return status of getrlimit for RLIMIT_CPU resource = %d\n",ret_get);

	printf("soft limit after = %ld\n",rlim_get.rlim_cur);
	printf("hard limit after = %ld\n",rlim_get.rlim_max);
	
}
