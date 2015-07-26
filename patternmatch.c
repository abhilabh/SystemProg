#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ncnt=0;
void patternmatch(char *filename,char *str)
{
	FILE *fp;
	char buf[100],*n;
	int count=1;
	if(filename!=NULL)
	fp=fopen(filename,"r");
	else
	fp=stdin;
	while(1)
	{
		n=fgets(buf,100,fp);
		if(n==NULL)
		break;
		if(strstr(buf,str))
		{
			printf("string found");
			if(ncnt==1)
			printf("%d",count);
			printf(" %s\n",buf);

			//fputs(buf,stdout);
		}
		count++;
	
	}

}

int main(int argc,char *argv[])
{
	int i;
	if(argc==3)
	{
		if(!strcmp(argv[1],"-n"))
		{
			ncnt=1;
			patternmatch(NULL,argv[1]);
			}
		else
			patternmatch(argv[2],argv[1]);

		}
	else if(argc==2)
	patternmatch(NULL,argv[1]);
	else
	{
		if(!strcmp(argv[1],"-n"))
		{
			ncnt=1;
		for(i=3;i<argc;i++)
			patternmatch(argv[i],argv[1]);
			}
		else
		for(i=2;i<argc;i++)
		patternmatch(argv[i],argv[1]);
		
		
	}
	return 0;
}
