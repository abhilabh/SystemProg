#include<stdio.h>
#include<string.h>
#include<assert.h>
void Strcpy(char *dest, char *src)
{
		assert(src != NULL);
		assert(dest != NULL);

		strcpy(dest, src);

}

main()
{

	Strcpy("ram", "ran");

}
