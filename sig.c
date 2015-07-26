#include <signal.h>
#include<stdio.h>
#include<unistd.h>
void sighandler(int sig)
{
   printf("pid %d received signal = %d\n", getpid(),sig);
}

int main (void)
{
	printf("parent pid = %d\n",getpid());
   signal (SIGQUIT, sighandler);   
	if(fork==0)
	{
		
		printf("child pid = %d\n",getpid());
	}
   while(1)
   {
   }
}
