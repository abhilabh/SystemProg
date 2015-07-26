#include <signal.h>
void sighandler(int sig)
{
   printf("received signal = %d\n", sig);
}

int main (void)
{
   signal (SIGINT, sighandler);   
   while(1)
   {
   }
}
