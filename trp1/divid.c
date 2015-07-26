#include<stdio.h>
#define MAXSIZE 20
void divide(int arr[],int *m)
{
	int i;
	m[0]=m[1]=m[2]=0;
	for(i=0;i<MAXSIZE;i++)
	{
		if(arr[i]!=0 && arr[i]%2==0)
			m[0]++;
		if(arr[i]!=0 && arr[i]%5==0)
			m[1]++;
		if(arr[i]!=0 && arr[i]%10==0)
			m[2]++;
	}
			
}

void main()
{
	static int arr[MAXSIZE];
	int m[3],n,i;
	printf("enter the number of element inserted maximum is 20:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("hello");
		scanf("%d",&arr[i]);
	}
	divide(arr,m);
	printf("number of element divisible by 2 is %d",m[0]);
	printf("number of element divisible by 5 is %d",m[1]);
	printf("number of element divisible by 10 is %d",m[2]);

}

