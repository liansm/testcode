#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
  int ret = 10;
  return (void *)ret;
}

int main(int argc, char *argv[]) {
  pthread_t thread;
  int *ret;

  ret = malloc(sizeof(int));
  pthread_create(&thread, NULL, thread_func, NULL);
  pthread_join(thread, (void **)ret);

  printf("thread return value: %d\n", *ret);

  free(ret);

  return 0;
}
