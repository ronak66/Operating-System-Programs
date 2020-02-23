#include <sched.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

char* schedule_policty(int val){
    if(val == 0) return "NORMAL";
    else if(val == 1) return "FIFO";
    else if(val == 2) return "RR";
    else if(val == 3) return "BATCH";
    else if(val == 5) return "IDLE";
    else if(val == 5) return "DEADLINE";
}

int main(void){
    long int curr_schedule = sched_getscheduler(0);
    printf("Current scheduling policy is %s\n", schedule_policty(curr_schedule));
    
    printf("Changing scheduling policy to FIFO\n");
    struct sched_param new_schedule;
    new_schedule.sched_priority = 50;
    sched_setscheduler(0,SCHED_FIFO, &new_schedule);

    curr_schedule = sched_getscheduler(0);
    printf("Current scheduling policy is %s\n", schedule_policty(curr_schedule));
    return 0;
}



