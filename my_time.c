#include<stdio.h>
#include<time.h>

int main()
{
	time_t t;
	struct tm *tmp;

	t=time(NULL);
	printf("%s",ctime(&t));
	tmp=localtime(&t);
	printf("%d:%d:%d",tmp->tm_hour,tmp->tm_min,tmp->tm_sec);
}
