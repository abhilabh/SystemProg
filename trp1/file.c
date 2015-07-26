#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE	1024

void readfile(int fd)
{
	int n;
	char buf[BUFSIZE];

	while (( n = read(fd, buf, BUFSIZE)) > 0)
	{
		write(1, buf, BUFSIZE);
	}
}

main(int argc, char *argv[])
{
	int fd;

	errno=0;
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		perror(argv[1]);
		return 1;
	}

	if (fd != -1)
	{
		int pid;
		
		pid = fork();
		
		if (pid == -1)
		{

		}
		else if (pid == 0)
		{	
			readfile(fd);
		}
		else
		{

		}
	}

	return 0;
}
