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
#include <wait.h>

int main(int argc, char* argv[]) {
  pid_t pid, sid;        // Variabel untuk menyimpan PID
  int status;
  pid = fork();     // Menyimpan PID dari Child Process
  char dir1[]="/home/ikul/Sisop/Praktikum2/soal2/";
  int mode=0;
  if(argc>1){
   if(!strcmp(argv[1],"-a")) mode=0;
   else if(!strcmp(argv[1],"-b")) mode=1;
   else{
     printf("Argumen salah\n");
     return 0;
   }
  }


  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir(dir1)) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  FILE* f = fopen("killer.c","w");
  fprintf(f, "#include <stdio.h>\n #include <signal.h>\n int main(){killpg(%d,SIGTERM);remove(\"killer\");}",(int)getpgid(getpid()));
  fclose(f);
  pid_t child_id3;
  child_id3 = fork();
  if(child_id3==0){
    char c[100]={0};
    char d[100]={0};
    strcat(c, dir1);
    strcat(c, "killer.c");
    strcat(d, dir1);
    strcat(d, "killer");
    char *arg[] = {"gcc", c, "-o", d, NULL};
    execv("/usr/bin/gcc", arg);
  }
  while ((wait(&status)) > 0);
  remove("killer.c");

  while (1) {
	char dirname[50];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(dirname,"%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	mkdir(dirname, 0777);

	pid_t child_id;

	child_id = fork();
	if(child_id==0){
		if(mode) setsid();
		pid_t child_id2;
		int cnt=0;
		while(cnt<20){
			child_id2 = fork();
			if(child_id2==0){
				char filename[50]={0};
				time_t t = time(NULL);
				struct tm tm = *localtime(&t);
				char nanti[40]={0};
				sprintf(nanti,"picsum.photos/%d",((int)t%1000)+100);
				sprintf(filename,"/%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
				char jadi[125]={0};
				strcat(jadi,dir1);
				strcat(jadi,dirname);
				strcat(jadi,filename);
				char *argv[] = {"wget","-q", "-O",  jadi, "--", nanti, NULL};
				execv("/usr/bin/wget", argv);
				return 0;
			}
			cnt++;
			sleep(5);

		}
		while ((wait(&status)) > 0);
		pid_t child_id4;
		child_id4 = fork();
		if(child_id4==0){
			char folder[125]={0};
			strcat(folder,dir1);
			strcat(folder,dirname);
			char hasil[150]={0};
			strcat(hasil, folder);
			strcat(hasil, ".zip");
			char *argv[] = {"zip", "-j","-r",  hasil, folder, NULL};
			execv("/usr/bin/zip", argv);
		}
		else{
			while ((wait(&status)) > 0);
			char folderr[170]={0};
			strcat(folderr,dir1);
			strcat(folderr,dirname);
			char *argv[] = {"rm","-r",folderr,NULL};
			execv("/bin/rm", argv);
		}
		
	}

	sleep(30);
  }
}
