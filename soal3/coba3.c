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
    int status;

    child_id = fork();

    if(child_id < 0){
        exit(EXIT_FAILURE);
    }
    if(child_id == 0) {
        child_id1 = fork();

        if(child_id1==0){ //1
            char *argv[] = {"mkdir", "-p", "indomie", NULL};
            execv("/bin/mkdir", argv);
        }
        else{ //2
            sleep(5);
            char *argv[] = {"mkdir", "-p", "sedaap", NULL};
            execv("/bin/mkdir", argv);
            
        }
    }
    else{
        while ((wait(&status)) > 0);
        child_id=fork();

        if(child_id==0){ //3
            char *argv[] = {"unzip","jpg.zip", NULL};
            execv("/usr/bin/unzip", argv);

        }else{
            while ((wait(&status)) > 0);
            child_id=fork();

            if(child_id==0){ //4

                char *argv[] = {"find", "/home/rekha/modul2/jpg/", "-mindepth", "1", "-maxdepth", "1", "-type", "f", "-exec", "mv", "-t", "/home/rekha/modul2/sedaap", "{}",";", NULL};
				execv("/usr/bin/find", argv);
            } else{

                while ((wait(&status)) > 0);
                child_id = fork();
                if(child_id==0){ //5

                    char *argv[] = {"find", "/home/rekha/modul2/jpg/", "-mindepth", "1", "-maxdepth", "1", "-type", "d", "-exec", "mv", "-t", "/home/rekha/modul2/indomie", "{}",";", NULL};
					execv("/usr/bin/find", argv);
                }else{

                    while ((wait(&status)) > 0);
                	child_id = fork();
                    if(child_id==0){ //6

                        char *argv[] = {"find", "/home/rekha/modul2/indomie/", "-mindepth", "1", "-maxdepth", "1", "-type", "d", "-exec", "touch", "{}/coba1.txt", "'\'", ";", NULL};
						execv("/usr/bin/find", argv);
                    }else{

                        while((wait(&status)) > 0);
						sleep(3); //7
                        char *argv[] = {"find", "/home/rekha/modul2/indomie/", "-mindepth", "1", "-maxdepth", "1", "-type", "d", "-exec", "touch", "{}/coba2.txt", "'\'", ";", NULL};
							execv("/usr/bin/find", argv);
                    }
                }
            }
        }
        
            
    }

}
  