
// Code to print the strings one per line using pointers
#include<stdio.h>
int main( )
{
        char *str[ ] = { "C language", "C++ language", "Java" };
        int k;
		  
        int elements =3 ;
		  

        for (k=0; k < elements; k++)
        {
          char *ptr=str[k];
       		puts(ptr);
          putchar('\n');
        }
    return 0;
}

