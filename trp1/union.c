#include <stdio.h>
struct un
{
	int  nx;	
	unsigned int uiy;
};

main()
{
	struct un num;
	num.nx=-1000;

	printf("num.nx = %u\n", num.nx);
	printf("num.nx = %d\n", num.nx);
	printf("num.uiy = %u\n", num.uiy);
	printf("num.uiy = %d\n", num.uiy);
}

