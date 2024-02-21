#include <stdio.h>
#include <stdlib.h>


static void print(char * string) {
  char * word;
  int counter;
  fflush(stdout);
  for(word = string; counter = *word++; )
  putc(counter, stdout);
}

int main(void) {
  typedef int pid_t;
  pid_t pid;
  if( (pid = fork()) < 0)
    exit(-2);
  else if( pid == 0)
    print("child");
  else print("parent\n");
  exit(0);
}

