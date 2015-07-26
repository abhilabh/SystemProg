
 #include "common.h"
 #define BUFSIZE 100

 void copy_stdin2stdout()
 {
	int n;
	char buf[BUFSIZE];
	while((n=read(0,buf,BUFSIZE))>0)
	{
//		printf("%s\n",buf);
		write(1,buf,n);
	}
 }
 void sendfile(int pd,char *filename)
 {
 	int fd,n;
	char buf[BUFSIZE];
	fd=open(filename,O_RDWR);
	while((n=read(fd,buf,BUFSIZE))>0)
	{
	//	printf("----n=%d\n",n);
		write(pd,buf,n);
	}

 }

 void file_upper(int pd,char *filename)
 {
 	int n,fd,i=0;
	char buf[BUFSIZE];
	fd=open(filename,O_WRONLY|O_CREAT|O_TRUNC,0777);
	while(n=read(pd,buf,BUFSIZE))
	{
		while(buf[i]=toupper(buf[i]))
		{
			i++;
		}
		write(fd,buf,n);
		write(1,buf,n);
		i=0;
	}
 
 }

void  main(int argc,char *argv[])

  {

    int pd[2];

    int pid;

    pipe(pd);

    pid = fork();

    if (pid == 0)

    {   // in child
      // dup2(pd[1], 1);

       close(pd[1]);
	   file_upper(pd[0],argv[2]);
	   close(pd[0]);

    }

    else

    {   // in parent

       //dup2(pd[0], 0);

       close(pd[0]);

       //close(pd[1]);

       sendfile(pd[1],argv[1]);
	   close(pd[1]);

		}
	   

	  }
