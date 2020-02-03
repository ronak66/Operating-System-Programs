#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	int ret1 = creat("./test_51.txt", 0777);
	int ret2 = creat("./test_52.txt", 0777);
	int ret3 = creat("./test_53.txt", 0777);
	int ret4 = creat("./test_54.txt", 0777);
	int ret5 = creat("./test_55.txt", 0777);
	while(1){
	}
	return 0;
}
