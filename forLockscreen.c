#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE] ;

    char *essid = NULL ;

    FILE *fp = popen("iw dev | awk '$1 == \"ssid\"{print $2}'", "r") ;

    if (fp == NULL)
    {
        perror("popen") ;
        exit(EXIT_FAILURE) ;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove trailing newline character, if present
        size_t len = strlen(buffer) ;
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0' ;
        }
        essid = strdup(buffer) ;
    }

    pclose(fp) ;

    if (essid != NULL)
    {
        printf("Connected to Wi-Fi network: %s\n", essid) ;
        if (strcmp(essid, "LAPTOP-S") == 0)
    
        {
            // Run the specified command if ESSID is "LAPTOP-S"
            printf("ESSID is LAPTOP-S. Running the specified command.\n") ;
            // system("feh --recursive --bg-fill --randomize /home/yash/walls/") ;
            system("betterlockscreen -u /home/yash/walls/")  ;
        }
        else
        {
            printf("ESSID is not LAPTOP-S. Running the specified command.\n") ;
            // system("feh --recursive --bg-fill --randomize /home/yash/walls/1") ;
            system("betterlockscreen -u /home/yash/walls/1")  ;
        }
        free(essid) ;
    }
    else
    {
        printf("Not connected to a Wi-Fi network.\n") ;
        // system("feh --recursive --bg-fill --randomize /home/yash/walls/1") ;
        system("betterlockscreen -u /home/yash/walls/1")  ;
    }

    return 0 ;
}
