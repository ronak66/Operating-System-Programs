#include<stdio.h>
#include<unistd.h>

int main(int argc, char** argv){
	int ret;
	ret = symlink("source","link_to_source");
	printf("status: %d\n", ret);
	return 0;
}
