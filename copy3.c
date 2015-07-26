#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void filecp(int source,int dest)
{
	int n;
	char buf[50];
	while(1)
	{
		
		n=read(source,buf,50);
		if(n<=0)
		break;
	//	printf("%d",n);
		write(dest,buf,n);
	}	
}
void filecopy()
{
	int fd1,fd2;
	fd1=open("cat.c",O_RDWR);
	fd2=open("ccc",O_RDWR);
	filecp(fd1,fd2);
//	printf("%d %d",fd1,fd2);
	close(fd1);
	close(fd2);
}

int main()
{
	int i=0;
//	if(argc==2)
	filecopy();
}
