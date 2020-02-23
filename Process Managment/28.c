#include <sched.h>
#include <stdio.h>


int main(void){

    long int max_val =  sched_get_priority_max(SCHED_FIFO);
    long int min_val = sched_get_priority_min(SCHED_FIFO);

    printf("The range for real time priority is %ld to %ld\n",min_val,max_val);
    return 0;
}
