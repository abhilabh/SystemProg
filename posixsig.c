#include <signal.h>
#include<stdio.h>
void sighandler(int sig)
{
    printf("received signal = %d\n", sig);
}

int main (void)
{
		struct sigaction action = { sighandler };
		sigaction(SIGINT, &action, NULL);
   while(1)
   {
   }
}
