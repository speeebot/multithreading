#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//volatile tells the compiler not to optimize anything to do with the variable
//->important when declaring global variables in multi-threaded applications
//https://stackoverflow.com/questions/20027238/understanding-volatile-variables-in-c
static volatile int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *function(void* arg)
{
  int i;
  pthread_mutex_lock(&lock);
  printf("%s: begin\n", (char*)arg);
  for(i=0; i < 1e7; i++)
    counter++;
  printf("%s: done\n", (char*)arg);
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main(int argc, char **argv)
{
  pthread_t p1, p2;

  pthread_mutex_init(&lock, NULL);
  pthread_create(&p1, NULL, function, "p1");
  pthread_create(&p2, NULL, function, "p2");
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  printf("main done with both threads (counter = %d)\n", counter);
  pthread_mutex_destroy(&lock);
  return EXIT_SUCCESS;
}

