#include<stdio.h>

void initialize()
{
	int i,a[9];
	for(i=0;i<=11;i++){
	a[i]=i;
	printf("we are here: %d\n",a[i]);
	}
}


main()
{
	printf("inside main: before initializing");
	initialize();
	printf("inside main: after initializing");

}
