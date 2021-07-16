#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//volatile tells the compiler not to optimize anything to do with the variable
//->important when declaring global variables in multi-threaded applications
//https://stackoverflow.com/questions/20027238/understanding-volatile-variables-in-c
static volatile int counter = 0;

void *function(void* arg)
{
  int i;
  printf("%s: begin\n", (char*)arg);
  for(i=0; i < 1e7; i++)
    counter++;
  printf("%s: done\n", (char*)arg);
  return NULL;
}

int main(int argc, char **argv)
{
  pthread_t p1, p2;

  pthread_create(&p1, NULL, function, "p1");
  pthread_create(&p2, NULL, function, "p2");
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);

  printf("main done with both threads (counter = %d)\n", counter);
  return EXIT_SUCCESS;
}

