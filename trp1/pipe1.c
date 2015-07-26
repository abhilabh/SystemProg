#include <stdio.h>
#include <stdlib.h>

int copy_stdin2out()
{


}

int main()
{
  int pd[2], pid;

 pipe(pd);
 pid = fork();

  if (pid == 0) 
  {  // in child
   dup2(pd[0], 0);
    close(pd[1]);
    close(pd[0]);
    copy_stdin2out();
    exit(0);
  }

  else  // in parent 
  {
   dup2(pd[1], 1);
    close(pd[0]);
    close(pd[1]);
    copy_stdin2out();
    wait(NULL);
    exit(0);
  }
}
