#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
  struct rlimit rlim;
  int ret = getrlimit(RLIMIT_CPU,&rlim);

  printf("Return status of getrlimit for RLIMIT_CPU resource = %d\n",ret);

  printf("Soft limit: %ld\n",rlim.rlim_cur);
  printf("Hard limit(ceiling for rlim_cur): %ld\n",rlim.rlim_max);
  return 0;
}
