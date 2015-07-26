#include <fcntl.h>
#include <sys/mman.h>
#include"common.h"
int main (int argc, char* argv[])
{
   int fd;
   void* filemap;
   long  filesize;
	struct stat st_stat;

	 fd = open (argv[1], O_RDONLY);
   // TODO:  get file size saved into the variable filesize
	fstat(fd,&st_stat);
	filesize=st_stat.st_size;
	 filemap = mmap(0, filesize, PROT_READ, MAP_PRIVATE, fd, 0); 
							// map entire file
   close (fd);	// file descriptor no longer needed
	 // TODO: use filemap to write the file content onto the screen
	 write(1,filemap,filesize);
   munmap (filemap, filesize);	// at the end unmap the file
}
