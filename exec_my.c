#include"common.h"
#include<unistd.h>
int main(int argc,char *argv[])
{
	int ret,pid;
//	char *arglist[]={"echo","hello","world",NULL};
char *arglist[]={NULL};
	pid=fork();
	switch(pid)
	{
		case 0: 
		if(ret==-1)
		printf("exec failed \n");
		ret = execl ("/bin/ls", "ls", "-l", (char *)0);
//		printf("%s\t%s\t%s\n",arg);

		case -1:
		printf("fork failed \n");

		default:
		printf("child created");
	}
}
