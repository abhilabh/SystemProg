#include<stdio.h>
void swap(int *a,int *b)
{

	int temp=*a;
	*a=*b;
	*b=temp;
}

void swap(float *a,float *b)
{

	float temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int a=4,b=5;
	float c=4.0,d=5.0;
	printf("a= %d b= %d",a,b);
	swap(&a,&b);
	printf("a= %d b= %d",a,b);
	swap(&c,&d);
	printf("a= %f b= %f",c,d);

}
