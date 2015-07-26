#include <stdio.h>

void cat()
{
        int c;

        while ( (c = getchar()) != EOF )
        {
                putchar(c);
        }
}

int main()
{
        cat();

        return 0;
}
