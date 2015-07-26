#include <stdio.h>

  #include <string.h>

 

  #define BUFSIZE   100

  int main()

  {

      int     n;

      int     fd[2];

      int     pid;

      char    *msg="one line of text\n";

      char    line[BUFSIZE];

      char    buf2[BUFSIZE*2];

 

      pipe(fd);

      pid = fork();

 

      if (pid > 0)

      {

        printf("created child -- %d\n", pid);

          close(fd[0]);
		  sleep(10);

          write(fd[1], msg, strlen(msg));

      }

      else if (pid == 0)

      {

          int n;
        printf("in parent -- \n");

          close(fd[1]);

          n = read(fd[0], line, BUFSIZE);

          n = sprintf(buf2, "pid - %d - %s\n", getpid(), line);

          write(1, buf2, n);

      }

      return(0);

  }
