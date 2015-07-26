#include <signal.h>
#include<stdio.h>

int main (void)
{
   signal (SIGINT, SIG_IGN);   
	printf("CTRL_C ignored\n");

	  sleep(30);  

  signal (SIGINT, SIG_DFL); 
	printf("CTRL_C restored\n");

	  sleep(1000);  
  
}
