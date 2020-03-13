#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <syslog.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    pid_t child_id;
    pid_t child_id1;

    child_id = fork();

    if(child_id < 0){
        exit(EXIT_FAILURE);
    }
    if(child_id == 0) {
        child_id1 = fork();

        if(child_id1==0){
            char *argv[] = {"mkdir", "-p", "indomie", NULL};
            execv("/bin/mkdir", argv);
        }
        else{
            sleep(5);
            char *argv[] = {"mkdir", "-p", "sedaap", NULL};
            execv("/bin/mkdir", argv);
            
        }
    }
    else{
        char *argv[] = {"unzip","jpg.zip", NULL};
        execv("/usr/bin/unzip", argv);
            
    }
}
  