#include<stdio.h>

void fun1(int *p)
{
	int k;
	for(k=0;k<6;k++)
	{
		(*p)++;
		++p;
		printf("%d\t",*p);

	}
	putchar('\n');

}
void fun2(int *p)
{
        int k;
	     for(k=0;k<6;k++)
		      {
		          *p++;
			         ++p;
						printf("%d\t",*p);
				 }
}
void main()
{
	int a[6]={1,5,8,12,17,25};
	fun1(a);
	fun2(a);
}
