#include<stdio.h>

struct n
{
	int a;
	char x;

}e1[5];
//p=e1;
int main()
{	
int i;
struct n *p=e1;
	for(i=0;i<5;i++)
	printf("\t%d",p++);
}
