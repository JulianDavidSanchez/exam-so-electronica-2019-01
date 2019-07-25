#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char*argv[]) {

printf("PROCESO: (pid:%d)\n", (int) getpid());

int rc = fork();

if (rc < 0) {     	// fork failed; exit

fprintf(stderr, "fork fallido\n");
exit(1);
} else if (rc == 0) { // child (new process)
printf("Soy el hijo con (pid:%d)\n", (int) getpid());
} else {          	// parent goes down this path (main)

printf("Soy el proceso padre de  %d  (pid:%d)\n",
rc, (int) getpid());
}

return 0;
}

