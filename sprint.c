#include<stdio.h>

int main()
{

	int a=1000,d;
	char b[25]={"dsjbdshfvbsdj"},buf[100],c[25];
	sprintf(buf,"%s %d",b,a);
	sscanf(buf,"%s%d",c,&d);
	printf("%s\n%d\n",c,d);

}
