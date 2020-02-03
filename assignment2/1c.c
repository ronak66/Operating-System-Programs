#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	int ret;
	ret = mkfifo("myfifo", 0777);
	printf("%d\n",ret);
	return 0;
}
