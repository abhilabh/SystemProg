#include "common.h"

main()
{
  int pd[2];
  int pid;
  pipe(pd);
  pid = fork();
  if (pid == 0)
  {   // in child 
  }
  else
  {   // in parent
     dup2(pd[1], 1);
     close(pd[0]);    
	  close(pd[1]);
	  copy_stdin2stdout();
     wait(NULL);
     exit(0);
  }
} 

 
copy_stdin2stdout()
{
    char buf[100];
    int n;
    while( (n = read(0, buf, 100)) > 0)
         write(1, buf, n);
    close(0);
    close(1);
}

