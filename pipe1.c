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

void  main()

  {

    int pd[2];

    int pid;

    pipe(pd);

    pid = fork();

    if (pid == 0)

    {   // in child
       dup2(pd[1], 1);

       close(pd[0]);

       close(pd[1]);

       copy_stdin2stdout();

    }

    else

    {   // in parent

       dup2(pd[0], 0);

       close(pd[0]);

       close(pd[1]);

       copy_stdin2stdout();

       wait(NULL);

       exit(0);

    }

  }

 

 
