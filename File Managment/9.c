#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

	int fd = open(argv[1],O_EXCL);
	struct stat fileStat;
	fstat(fd,&fileStat);
	printf("Inode number: %ld\n",fileStat.st_ino);
	printf("Number of links: %ld\n",fileStat.st_nlink);
	printf("uid:  %d\n",fileStat.st_uid);
	printf("gid: %d\n",fileStat.st_gid);
	printf("size: %ld\n",fileStat.st_size);
	printf("block size: %ld\n",fileStat.st_blksize);
	printf("nunber of blocks: %ld\n",fileStat.st_blocks);
	printf("time of last access: %ld\n",fileStat.st_atime);
	printf("time of last modifiation:  %ld\n",fileStat.st_mtime);
	printf("time of last change: %ld\n",fileStat.st_ctime);
	return 0;
}
