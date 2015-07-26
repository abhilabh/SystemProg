#include"common.h"

#define BUFSIZE 100

 int main(int argc, char *argv[])

  {

    int fd,fd1, spcount, n, k;

    char buf[BUFSIZE+1];
	fd1=open("try.c",O_RDONLY);
	n=read(fd1,buf,BUFSIZE);

    mkfifo("fifo", 0660);

    fd = open("fifo", O_WRONLY);

    n = write(fd, buf, BUFSIZE);

//    buf[n] = 0;

//    printf("%s\n", buf);

    spcount = 0;

    for (k=0; k < n; ++k) {

      if (buf[k] == ' ') ++spcount;

    }

    printf("%d\n", spcount);

  }
