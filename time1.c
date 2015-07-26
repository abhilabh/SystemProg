#include<stdio.h>
#include<time.h>


int main()
{
    for(;;)
    {
        printf ("%ld\n", time(NULL));
        printf ("%f\n", time(NULL));
        sleep(1);
    }
    return 0;
}
