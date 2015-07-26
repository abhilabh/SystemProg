#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFSIZE 100
int main(int argc,char *argv[])
{
	int fd,pid,n;
//	int n;
	char buf[BUFSIZE];
	fd=open(argv[1],O_RDONLY);
//	pid=fork();
	if((pid=fork())==-1)
	{
		printf("fork fails");
	}
	if(pid==0)
	{
	//	printf("in child --%d--",fd);
		while(1)
		{
			n=read(fd,buf,BUFSIZE);
			if(n<=0)
			break;
			write(1,buf,n);
		}
	}
	if(pid>0)
	close(fd);
	return 0;

}
