#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int m=1;
void filecopy(int source,int dest)
{
	int n;
	char buf[50];
	while(1)
	{
		n=read(source,buf,50);
		if(n<=0)
		break;
		write(dest,buf,n);
	}
}
void filecat(char *filename1,char *filename2)
{
	int fd1,fd2;
	fd1=open(filename1,O_RDWR);
//	fd2=open(filename2,O_CREAT,0777);
//	printf("file does exist%d",fd2);
	if( m==0)
	fd2=open(filename2,O_RDWR);
	else
	fd2=open(filename2,O_CREAT,0777);

	
	filecopy(fd1,fd2);
	close(fd1);
	close(fd2);

}
void main(int argc,char *argv[])
{
//int m=1;
	if(argc==3)
	{
		filecat(argv[1],argv[2]);

	}
	else
	{
		if(!strcmp(argv[1],"-f"))
		{
			m=0;
			filecat(argv[2],argv[3]);
		}
	}


}
