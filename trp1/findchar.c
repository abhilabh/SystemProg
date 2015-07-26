#include<stdio.h>

int findchar(char*,char);
void main()
{
	int i;
	char a[]={"hello"},ch='l';
	i=findchar(a,ch);
		if(i==-1)
			printf("character is not found");
		else
		{
			printf("the first position of character %c in %s is %d",ch,a,i);
	
			}
} 
void test(char str[],ch)
{
	i=findchar(str,ch);
		if(i==-1)
	  	printf("character is not found")
	   else
	   {
		            printf("the first position of character %c in %s is %d",ch,a,i);
		            
			         			 
	 	}
		pree_and_succeed(stlen(str),i);

}
void pre_and_succeed(int l,int i)
{
	if(i==0)
	{
	printf("there is no preceding character");



int findchar(char str[],char ch)
{
	int i=0;
	//printf("%s",str);
	while(str[i]!='\0')
	{
		
		if(str[i]==ch)
		{
			printf("%s",str);
			return i;
		}
		i++;
}
return -1;
	
}
