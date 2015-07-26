#include <string.h>

void printmsg(char str[],int count)
{
	int i;
	for(i=0;i<count;i++)
	printf("%s\n",str);

}
main(int argc, char *argv[ ])
{
   char str[20];
   int  count=10;		// default count value
   int  k;
	if(!strcmp(argv[1],"msg"))
	{
  	 for ( k = 1; k < argc-1; k++)      
		{

	      if ( argv[k][0] == '-' )         
			{
        // process option
      	  switch( argv[k][1] )
   	     {
         	  case 'm':
              // the next argument is 
              //  the string to be printed
              // copy it into str
					  strcpy(str,argv[k+1]);

             	 break;
          		case 'n':
              // the next argument is 
              //  the count 
				 		 if(argv[k+1][0]>'0' && argv[k+1][0]<='9')
				 		 {
							count=atoi(argv[k+1]);
				 		 }
				 		 else
				  				 printf("invalid option");

             	 break;

           		 default:
              			  printf("invalid option");
               	 return (1);
  			      }
      

  			}
		}
		}
	else 
	
		printf("invalid option");
   printmsg(str, count);
	
   return 0;
}
