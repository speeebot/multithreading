#include <stdio.h>
#include <stdlib.h>
#include <thread.h>

void *function(void* unused)
{
  int i;
  for(i=0; i < 20000; i++)
    printf("%d/n", i);
}

int main(int argc, char **argv)
{
  pthread_t p1;

  pthread_create(&p1, NULL, function, NULL);
  printf("from main thread\n");
  pthread_join(p1, NULL);

  return EXIT_SUCCESS
}

