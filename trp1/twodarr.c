#include<stdio.h>

void main()
{
	int arr[2][2]={1,2,3,4};
	int *p;
	p=arr;
	printf("%d",*p++);
}
