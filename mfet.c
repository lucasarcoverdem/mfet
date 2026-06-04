#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char login[1024];
char hostname[1024];
char os[1024];
char memory[1024];


void get_os_pretty_name()
{
    FILE* os_release_file = fopen("/etc/os-release", "r");

    char line[1024];

    while (fgets(line, sizeof(line), os_release_file))
    {
        if (strncmp(line, "PRETTY_NAME=", 12) == 0)
        {
    	    char* line_start = line+13;
	    char* line_end = strrchr(line_start, '"');	    

            if (line_end)
	        *line_end = '\0';

            strcpy(os, line_start);
            break;
        }
    }

    fclose(os_release_file);
}

int main(int argc, char** argv)
{
    login[1023] = '\0';
    getlogin_r(login, sizeof(login));

    hostname[1023] = '\0';
    gethostname(hostname, sizeof(hostname));

    get_os_pretty_name();
    
    printf("%s@%s\n", login, hostname);
    printf("------------\n");
    printf("os : %s\n", os);

    return 0;
}

