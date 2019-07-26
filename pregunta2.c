#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

float v = 0;

void *parte1(void *argc) {
float y = 350;
float z = 25;
v = z/y;
printf("Hilo 1 operando v = z/y: %f \n", v);
}

void *parte2(void *argc){
sleep(2);
int x = 1250;
v = x*v;
printf("Hilo 2 operando x*v: %f\n", v);
}

int main(int argc, char*argv[]) {

pthread_t p1, p2;

pthread_create(&p1, NULL, parte1, NULL);
pthread_create(&p2, NULL, parte2, NULL);

pthread_join(p1, NULL);
pthread_join(p2, NULL);
printf("Demostración de resultado de variable global: %f\n", v); //Confirmar.
return 0;
}

