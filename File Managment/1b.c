#include<stdio.h>
#include<unistd.h>

int main(){

	int ret;
	ret = link("source", "hard_link_to_source");
	printf("status: %d\n",ret);
	return 0;
}
