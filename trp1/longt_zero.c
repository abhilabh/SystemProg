#include<stdio.h>
void search(char str[])
{
	int m=1,i=0,len1,len2,pos;
	len1=len2=pos=0;
	printf("%s\n",str);
	while(str[i]!='\0') //termination condition
	{
		if((str[i]=='0') && (m==1))	//condition longest zero at the start
		{
			len1++;
			if(str[i+1]=='1')	//condition for continuos zeros
			{
				m=0;
				pos=i+1-len1;

			}
		}
		else if((str[i]=='0') &&(m==0))	//condition for second cosecutive zer
		{
			len2++;
			if(str[i+1]=='1' || str[i+1]=='\0')
			if(len1<len2)
			{
				len1=len2;
				len2=0;
				pos=i+1-len1;

			}
			else if(len1==len2)
			{
				printf
			}

			else len2=0;
		}

		i++;
	}
	printf("Maximum length of zero=%d \t start position=%d\n",len1,pos);
}	

void main()
{
	char str[]={"110001100000100000111"};
	search(str);
	
	
	search("1000011110000000");
	search("10000111100111000");

}
