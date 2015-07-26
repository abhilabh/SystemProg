#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int i=0,n;
	int fd1,fd2;
	char buf[50];
	fd1=open("cat.c",O_RDWR);
	while(1)
	{
		
		n=read(fd1,buf,50);
		if(n<=0)
		break;
	//	printf("%d",n);
		write(1,buf,n);
	}	
//	if(argc==2)
close(fd1);
}
