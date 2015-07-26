#include <stdio.h>
#include <errno.h>
extern int  errno;
int n=0;
#define BUFSIZE 1024
/* void filecopy( FILE* source, FILE *dest )
 {
      char *s;
		char buf[BUFSIZE];
  //    printf("%d ",count);
      while (1)
        {
                 // 1. get character from source file
                 s = fgets(buf,BUFSIZE,source);

                //2. if end-of-file come out of the loop
                if (s == NULL)  break;
              // 3. otherwise, put character into dest file
                 fputs(buf, dest);
               //  if((c=='\n') &&( n==1))
               //  printf("%d ",++count);

        }
 }
*/

void filecopy( FILE* source, FILE *dest )
{
        char  c;
		  int count=1;
		   printf("%d ",count);
        while (1)
        {
                // 1. get character from source file
                c = fgetc(source);

                //2. if end-of-file come out of the loop
                if (c == EOF)  break;

                // 3. otherwise, put character into dest file
					 fputc(c, dest);

					 if((c=='\n') &&( n==1))
					 printf("%d ",++count);
               
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
//	int n=0;
    if (argc == 1)       {
        filecopy(stdin, stdout);
    }
    else   {
        int k;
//		  if(!strcmp(argv[1],"-n"))
//		  n=1;
        for(k=1; k<argc; k++)
        {
		  		if(!strcmp(argv[1],"-n"))
				{
					 n=1;
					catfile( argv[2 ]);
					k++;

				}
				else
            catfile( argv[k] );
        }
    }
    return 0;
}

