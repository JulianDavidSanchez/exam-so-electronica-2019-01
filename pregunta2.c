#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

volatile float v = 0;

void *math(void *argc) {
float y = 350;
float z = 25;
v = z/y;
printf("Hilo 1 con z/y: %f \n", v);
}

void *final(void *argc){
sleep(2);
int x= 1250;
int f = x*v;
printf("Hilo 2 con operación x*v: %d\n", f);
}

int main(int argc, char*argv[]) {

pthread_t p1, p2;

//printf("Initial value : %d\n", p);


pthread_create(&p1, NULL, math, NULL);

pthread_create(&p2, NULL, final, NULL);

pthread_join(p1, NULL);

pthread_join(p2, NULL);

//printf("Final value : %d\n", v);

return 0;

}

