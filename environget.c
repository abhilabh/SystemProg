#include<stdlib.h>
#include<stdio.h>
int main(void)
{
char *s;
s = getenv("LOGNAME");
if (s == NULL)
printf("variable not found\n");
else
printf("value is \"%s\"\n", s);
exit(EXIT_SUCCESS);
}
