#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void filecp(int source,int dest)
{
	int n;
	char buf[51];
	while(1)
	{
		
		n=read(source,buf,50);
		if(n<0)
		break;
	//	printf("%d",n);
		write(dest,buf,n);
	}	
}
void filecopy(char *filename1,char *filename2)
{
	int fd1,fd2;
	fd1=open(filename1,O_RDWR);
	fd2=open(filename2,O_RDWR);
	filecp(fd1,fd2);
	close(fd1);
}

int main(int argc,char *argv[])
{
	int i=0;
//	if(argc==2)
	filecopy(argv[1],argv[2]);
}
