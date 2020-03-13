#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <signal.h>  

//proses untuk menjalankan exec bash
void run_command(char* dir)
{
  signal(SIGCHLD, SIG_IGN);
  pid_t pid, sid;
  pid = fork();
  if (pid == 0) {
    sid = setsid();

    if (sid < 0) {
      exit(EXIT_FAILURE);
    }

    execlp("bash", "bash", dir, (char *)NULL);
  }
}

int check_argument(int argc, char *argv[]) {
  int salah = 0;
  if (argc != 5) salah = 1;
  if (strcmp(argv[1], "*")) {
    salah += 1;
    for (int i = 0;i<60;i++) {
      char s[2] = "";
      sprintf(s, "%d", i);
      if (!strcmp(argv[1], s)) {
        i = 60;
        salah -= 1;
      }
    }
  }
  if (strcmp(argv[2], "*")) {
    salah += 1;
    for (int i = 0;i<60;i++) {
      char s[2] = "";
      sprintf(s, "%d", i);
      if (!strcmp(argv[2], s)) {
        i = 60;
        salah -= 1;
      }
    }
  }
  if (strcmp(argv[3], "*")) {
    salah += 1;
    for (int i = 0;i<24;i++) {
      char s[2] = "";
      sprintf(s, "%d", i);
      if (!strcmp(argv[3], s)) {
        i = 24;
        salah -= 1;
      }
    }
  }
  if (salah) {
    printf("Argumen salah!\n");
    return -1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  
  if (check_argument(argc, argv) == -1) return 0;

  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {

    time_t now = time(NULL);
    struct tm tm = *localtime(&now);

    int se, mi, h;
    se = tm.tm_sec;
    mi = tm.tm_min;     // 0-59
    h = tm.tm_hour;     // 0-23

    char sse[3], smi[3], sh[3];
    sprintf(sse, "%d", se);
    sprintf(smi, "%d", mi);
    sprintf(sh, "%d", h);

    if ((!strcmp(sse, argv[1]) || !strcmp(argv[1], "*")) && 
        (!strcmp(smi, argv[2]) || !strcmp(argv[2], "*")) && 
        (!strcmp(sh, argv[3]) || !strcmp(argv[3], "*"))) {
      run_command(argv[4]);
    }
    sleep(1);
  }
  
  exit(EXIT_SUCCESS);
}
