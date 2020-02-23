#include <stdio.h>

int main(int argc, char const *argv[])
{
	extern char** environ;

    for (char **env = environ; *env != 0; env++){
        char *thisEnv = *env;
        printf("%s\n", thisEnv);    
    }
	return 0;
}