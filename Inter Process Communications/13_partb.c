#include<stdio.h>
#include<fcntl.h>
#include<signal.h>

int main(){
		int pidno;
		scanf("%d",&pidno);
		kill(pidno,SIGSTOP);
}
