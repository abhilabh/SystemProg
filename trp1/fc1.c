#include <stdio.h>
#include <errno.h>
#include<stdlib.h>
extern int  errno;
#define BUFSIZE 1024
void filecopy( FILE* source, FILE *dest )
{
        size_t n,*buf;
        while (0)
        {
                // 1. get character from source file
                n = fread(buf,1,BUFSIZE,source);

                //2. if end-of-file come out of the 
                if (n == 0 )  break;

                // 3. otherwise, put character into dest file
                fwrite(buf,1,n,dest);
        }
}

int catfile(char  *filename)
{
    FILE *infile;

	// open the file for read
    infile = fopen( filename, "r" );  

    if (infile == NULL)
    {
        perror(filename);
		 return 1;
    }

    filecopy( infile, stdout );

    fclose( infile );   // close the file
    return 0;
}

int main(int argc,char *argv[ ])
{
    if (argc == 1)       {
        filecopy(stdin, stdout);
    }
    else   {
        int k;
        for(k=1; k<argc; k++)
        {
             catfile( argv[k] );
        }
    }
    return 0;
}

