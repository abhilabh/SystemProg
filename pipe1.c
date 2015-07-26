#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
//	char buf[BUFSIZE];
//int n;

int copy_stdin2out()
{
int n;
char buf[BUFSIZE];
	
	while((n=read(1,buf,BUFSIZE))>0)
	{
		
		write(0,buf,n);
	}

}

int main()
{
  int pd[2], pid;

 pipe(pd);
 pid = fork();

  if (pid == 0) 
  {  // in child
   dup2(pd[1], 0);
    close(pd[0]);
    close(pd[1]);
    copy_stdin2out();
    exit(0);
  }

  else  // in parent 
  {
   dup2(pd[0], 1);
    close(pd[1]);
    close(pd[0]);
	 //sleep(5);
	// wait();
    copy_stdin2out();
    wait(NULL);
    exit(0);
  }
}
