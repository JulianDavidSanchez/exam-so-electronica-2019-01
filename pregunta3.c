#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int pidp;
int pidh;

int main(int argc, char*argv[]) {

printf("PROCESO: (pid:%d)\n", (int) getpid());

int rc = fork();

if (rc < 0) {     	// fork failed; exit

fprintf(stderr, "fork fallido\n");
exit(1);
} else if (rc == 0) { // child (new process)
wait(&pidh);
printf("Soy el hijo con (pid:%d)\n", (int) getpid());
} else {          	// parent goes down this path (main)
pidh = (int) getpid();
printf("Soy el proceso padre de  %d  (pid:%d)\n",
rc, pidh);
}

return 0;
}

