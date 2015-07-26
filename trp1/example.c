#include<stdio.h>

int main()
{
	int a[]={10,20,30,40,50};
	int n,k,y,*p;
	n=sizeof(a)/sizeof(a[0]);
	p=a;
	for(k=0;k<n;k++)
	{
		y=(*p++)+1;
		printf("%d\t%d\n",y,a[k]);

	}
	return 0;
}

