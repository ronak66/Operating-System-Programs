#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	int ret1 = creat("./test_51.txt", 0777);
	printf("Status1: %d\n",ret1);
	int ret2 = creat("./test_52.txt", 0777);
	printf("Status2: %d\n",ret2);
	int ret3 = creat("./test_53.txt", 0777);
	printf("Status3: %d\n",ret3);
	int ret4 = creat("./test_54.txt", 0777);
	printf("Status4: %d\n",ret4);
	int ret5 = creat("./test_55.txt", 0777);
	printf("Status5: %d\n",ret5);
	while(1){
	}
	return 0;
}
