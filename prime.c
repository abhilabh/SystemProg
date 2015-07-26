#include<stdio.h>

int isprime(int num)
{
	int j;
	
		for(j=2;j<=num/2;j++)
		{
			if(num%j!=0)
			continue;
			else
			return 0;
		}
		return 1;
}
int main()
{
	int i;
	for(i=2;i<10;i++)
	if(isprime(i))
	printf("%d is aprime",i);
}
