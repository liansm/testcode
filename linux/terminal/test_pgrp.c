#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  pid_t pgrp;

  pgrp = tcgetpgrp(STDIN_FILENO);
  if (pgrp == -1) {
    perror("tcgetpgrp");
    exit(EXIT_FAILURE);
  }

  printf("The controlling terminal process group ID is %d\n", pgrp);

  sleep(300);
  return EXIT_SUCCESS;
}
