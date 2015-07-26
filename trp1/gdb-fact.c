#include <stdio.h>

long  fact(int n)
{
    long result=1;

    while(n)
    {
        result *= n;
		  n--;
    }
    return result;
}


int main(int argc, char *argv[])
{
	 int n,i;
	 long val;
	 //for(i=1;i<argc;i++){
	 n= atoi(argv[1]);
     val=fact(n);
	 
    printf("%d! = %ld\n", n,val);
	 //}
    return 0;
}
 
