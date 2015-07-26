#include <stdio.h>

struct d
{
   int a;
   float  f;
   char *p;
};

struct d  sd = { 1, 2.5, 0 };

int foo(void *p)
{
    printf("in foo\n");
        return 0;
}

void* dummy(int x)
{
    printf("in dummy x = %d\n",x);
        return 0;
}

main()
{
  int i,a[9] ;
         printf("My first go at the gdb\n") ;
         for( i=0;i<=11; i++ )
         {
 a[i] = i ;
                printf("we are here: %d\n",a[i]);
                dummy(a[i]);
                foo(NULL);
         }
}

