#include<stdio.h>
main( int argc, char *argv[ ] )
	{
    	 int k,sum=0;

	    for( k=1; k < argc; k++)
    	{
       		int val;

        	val = atoi( argv[k] );
			sum+=val;
	}
     	printf("sum = %d\n", sum);
     	return 0;
	}

