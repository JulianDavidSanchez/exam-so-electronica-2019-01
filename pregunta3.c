#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>

int pidp;
int pidh;

int main(int argc, char*argv[]) {

	int *number = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	
	*number = 0;
	int rc = fork();

	if (rc < 0) {    // EN caso de fork fallido, salir.

	  fprintf(stderr, "fork fallido\n");
	  exit(1);
	} else if (rc == 0) { // HIJO.

	while(*number != 1); //condición para iniciar código
	//CÓDIGO DEL HIJO
	printf("\n");
        printf("He esperado que termine mi padre, soy el Hijo con pid: %d\n", (int) getpid());
        printf("Ya puedo iniciar mi código\n");
	//CÓDIGO DEL HIJO, SEA LO QUE HAGA.
	} else { //PADRE.

	printf("Soy el proceso padre de  %d  (Mi es pid:%d)\nDormiré 2 segundos...\n",rc, (int) getpid());
	sleep(2);
	printf("Me desperté. Ya voy a terminar, adelante Hijo\n");
	*number = 1; //activador de hijo. Debe ir al final del código del padre.
        sleep(1); //Lo pongo para que no se junte tanto texto.
	}

	munmap(number, sizeof(int)); //liberar memoria.
	return 0;
}

