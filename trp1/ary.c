#include <stdio.h>
#define MAX 10


void process_ary(int a[], int cnt)
{
	int ndiv2cnt=0, ndiv5cnt=0, ndiv2n5cnt=0;
	int d2,d5, k; 

	for (k=0; k<MAX; k++)
	{
		if ( a[k] % 2 )
		{
			++ndiv2cnt;
			d2=1;
		}

		if ( a[k] % 5 )
		{
			++ndiv5cnt;
			d5=1;
		}

		if ( d2 && d5 )
		{
			++ndiv2n5cnt;
			
		}
		d2=d5=0;

	}

	printf("nos. divisible by 2      = %d\n", ndiv2cnt);
	printf("nos. divisible by 5      = %d\n", ndiv5cnt);
	printf("nos. divisible by 2 & 5  = %d\n", ndiv2n5cnt);

}


int main()
{
	int a[MAX];

	int k;

	for(k=0; k<MAX; k++)
		scanf("%d", &a[k]);

	process_ary(a, MAX);

	return 0;

}

