#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>

#include <stdio.h>

int main(int argc, char* argv[]) {
	struct stat fileInfo;
	struct timespec timeinfo;

	stat(argv[1], &fileInfo);
    /*
    The bitmask for all file type fields is S_IFMT. 
    By anding this value with the st_mode value, 
    we can extract the file type information from the file’s mode field. 
    We recall here that anding is used to apply a mask to a binary value. 
    */
 	switch (fileInfo.st_mode & S_IFMT) {
     case S_IFREG:
            printf("Regular File\n");
            break;
        case S_IFDIR:
            printf("Directory\n");
            break;
        case S_IFBLK:
            printf("Block Device\n");
            break;
        case S_IFCHR:
            printf("Character Device\n");
            break;
        case S_IFSOCK:
            printf("Socket\n");
            break;
        case S_IFLNK:
            printf("Symbolic Link\n");
            break; 
    }
    return 0;
}