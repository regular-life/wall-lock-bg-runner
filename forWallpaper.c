#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 256

// Global variables
char *essid = NULL ;
pthread_mutex_t essid_mutex = PTHREAD_MUTEX_INITIALIZER ;

void updateEssid(const char *newEssid)
{
    // Lock the mutex before updating the shared resource
    pthread_mutex_lock(&essid_mutex) ;

    // Free the previous value, if any
    if (essid != NULL) 
    {
        free(essid) ;
        essid = NULL ;
    }

    // Duplicate the new value
    essid = strdup(newEssid) ;

    // Unlock the mutex after updating the shared resource
    pthread_mutex_unlock(&essid_mutex) ;
}

void processEssid() 
{
    // Lock the mutex before accessing the shared resource
    pthread_mutex_lock(&essid_mutex) ;

    // Access the shared resource
    if (essid != NULL) 
    {
        printf("Connected to Wi-Fi network: %s\n", essid) ;
        if (strcmp(essid, "LAPTOP-S") == 0) 
        {
            // Run the specified command if ESSID is "LAPTOP-S"
            printf("ESSID is LAPTOP-S. Running the specified command.\n") ;
            system("feh --recursive --bg-fill --randomize /home/yash/walls/") ;
            // system("betterlockscreen -u /home/yash/walls/")  ;
        }
        else 
        {
            printf("ESSID is not LAPTOP-S. Running the specified command.\n") ;
            system("feh --recursive --bg-fill --randomize /home/yash/walls/1") ;
            // system("betterlockscreen -u /home/yash/walls/1")  ;
        }
    }
    else 
    {
        printf("Not connected to a Wi-Fi network.\n") ;
        system("feh --recursive --bg-fill --randomize /home/yash/walls/1") ;
        // system("betterlockscreen -u /home/yash/walls/1")  ;
    }

    // Unlock the mutex after accessing the shared resource
    pthread_mutex_unlock(&essid_mutex) ;
}

int main() 
{
    char buffer[MAX_BUFFER_SIZE] ;
    FILE *fp = popen("iw dev | awk '$1 == \"ssid\" {print $2}'", "r") ;

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

        // Update the shared resource with the new ESSID
        updateEssid(buffer) ;
    }

    pclose(fp) ;

    // Process the ESSID
    processEssid() ;

    return 0 ;
}
