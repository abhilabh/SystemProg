#include <fcntl.h>
#include <sys/mman.h>
int main (int argc, char* argv[])
{
   int fd;
   void* filemap;
   long  filesize;

	 fd = open (argv[1], O_RDONLY);
   // TODO:  get file size saved into the variable filesize
	 filemap = mmap(0, filesize, PROT_READ, MAP_PRIVATE, fd, 0); 
							// map entire file
   close (fd);	// file descriptor no longer needed
	 // TODO: use filemap to write the file content onto the screen
   munmap (filemap, filesize);	// at the end unmap the file
}
