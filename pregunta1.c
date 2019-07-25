#include <stdio.h>
#include <stdlib.h>
#include "mycommon.h"

volatile int counter = 0;
int loops;
puerta(puerta);


void*worker(void*arg) {

int i;
cerrar_puerta(puerta);
for (i = 0; i < loops; i++) {

counter++;

}
abrir_puerta(puerta);
return NULL;

}

int main(int argc, char*argv[]) {

crear_puerta(puerta);

if (argc != 2) {

fprintf(stderr, "usage: threads <value>\n");

exit(1);

}

loops = atoi(argv[1]);

pthread_t p1, p2;

printf("Initial value : %d\n", counter);


pthread_create(&p1, NULL, worker, NULL);

pthread_create(&p2, NULL, worker, NULL);

pthread_join(p1, NULL);

pthread_join(p2, NULL);
destruir_puerta(puerta);
printf("Final value : %d\n", counter);

return 0;

}

