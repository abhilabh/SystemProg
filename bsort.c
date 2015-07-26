#include<stdio.h>
#include<string.h>

void bubble_sort(int *a,int start,int size)
{
	int i,j;
	for(i=start;i<size;i++)
	{
		for(j=start;j<size-1;j++)
		{	
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			
		}
	}
}

int main()
{
	int i,a[8]={3,4,1,45,23,7,8,2};
	for(i=0;i<8;i++)
	printf("%d\t",a[i]);
	putchar('\n');
	bubble_sort(a,4,8);
	for(i=0;i<8;i++)
	printf("%d\t",a[i]);
}
