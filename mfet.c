#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char login[1024], hostname[1024], os[1024];
long mem_total, mem_available;

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

void get_memory()
{
    FILE* memory_file = fopen("/proc/meminfo", "r");

    fscanf(memory_file, "MemTotal: %ld kB\n", &mem_total);
    char line[128];
    
    while(fgets(line, sizeof(line), memory_file))
        if (sscanf(line, "MemAvailable: %ld kB\n", &mem_available) == 1)
            break;
    
    fclose(memory_file);    
}

int main(int argc, char** argv)
{
    login[1023] = '\0';
    getlogin_r(login, sizeof(login));

    hostname[1023] = '\0';
    gethostname(hostname, sizeof(hostname));

    get_os_pretty_name();
    
    get_memory();
    
    int len = strlen(login) + strlen(hostname) + 1;

    printf("%s@%s\n", login, hostname);
    for (int i = 0; i<len; i++)
        putchar('-');
    putchar('\n');

    printf("os : %s\n", os);
    printf("ram: %ld mb / %ld mb\n", (mem_total - mem_available) / 1024, mem_total / 1024);

    return 0;
}

