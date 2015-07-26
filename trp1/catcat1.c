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
#include <stdio.h>

void cat()
{
        int c;

        while ( (c = getchar()) != EOF )
        {
                putchar(c);
        }
}

int main()
{
        cat();

        return 0;
}
#include<stdio.h>
void char2bin(unsigned char uc, char *sbin)
{
    union u
    {
       unsigned char uc;
       struct
       {
          unsigned char b0:1;
          unsigned char b1:1;
          unsigned char b2:1;
          unsigned char b3:1;
          unsigned char b4:1;
          unsigned char b5:1;
          unsigned char b6:1;
          unsigned char b7:1;
       } bits;
    }  u;

    u.uc = uc;
    sbin[0] = '0' + u.bits.b7;
    sbin[1] = '0' + u.bits.b6;
    sbin[2] = '0' + u.bits.b5;
    sbin[3] = '0' + u.bits.b4;
    sbin[4] = '0' + u.bits.b3;
    sbin[5] = '0' + u.bits.b2;
    sbin[6] = '0' + u.bits.b1;
    sbin[7] = '0' + u.bits.b0;
    sbin[8] = 0;    // terminate with 0
}
void main()
{
	char ch=65,sbin[9];
	char2bin(ch,sbin);
	printf("%s",sbin);

}

int main(int argc, char *argv[])
{
	int i;
	printf("in main\n");

	printf("argc = %d\n", argc);
	for(i=0;i<=argc;i++)
	{
		printf("argv[%d] = %s\n",i,argv[i]);
	}
	return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void filecp(int source,int dest)
{
	int n;
	char buf[51];
	while(1)
	{
		
		n=read(source,buf,50);
		if(n<0)
		break;
	//	printf("%d",n);
		write(dest,buf,n);
	}	
}
void filecopy(char *filename1,char *filename2)
{
	int fd1,fd2;
	fd1=open(filename1,O_RDWR);
	fd2=open(filename2,O_RDWR);
	filecp(fd1,fd2);
	close(fd1);
}

int main(int argc,char *argv[])
{
	int i=0;
//	if(argc==2)
	filecopy(argv[1],argv[2]);
}
#include<stdio.h>

int main()
{
	int i;

	for(i=1;i<argv;i++)
	{
	
	}

}
#include<stdio.h>
#define MAXSIZE 20
void divide(int arr[],int *m)
{
	int i;
	m[0]=m[1]=m[2]=0;
	for(i=0;i<MAXSIZE;i++)
	{
		if(arr[i]!=0 && arr[i]%2==0)
			m[0]++;
		if(arr[i]!=0 && arr[i]%5==0)
			m[1]++;
		if(arr[i]!=0 && arr[i]%10==0)
			m[2]++;
	}
			
}

void main()
{
	static int arr[MAXSIZE];
	int m[3],n,i;
	printf("enter the number of element inserted maximum is 20:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("hello");
		scanf("%d",&arr[i]);
	}
	divide(arr,m);
	printf("number of element divisible by 2 is %d",m[0]);
	printf("number of element divisible by 5 is %d",m[1]);
	printf("number of element divisible by 10 is %d",m[2]);

}

#include<stdio.h>

int main()
{
	int a[]={10,20,30,40,50};
	int n,k,y,*p;
	n=sizeof(a)/sizeof(a[0]);
	p=a;
	for(k=0;k<n;k++)
	{
		y=(*p++)+1;
		printf("%d\t%d\n",y,a[k]);

	}
	return 0;
}

#include<stdio.h>

void fun1(int *p)
{
	int k;
	for(k=0;k<6;k++)
	{
		(*p)++;
		++p;
		printf("%d\t",*p);

	}
	putchar('\n');

}
void fun2(int *p)
{
        int k;
	     for(k=0;k<6;k++)
		      {
		          *p++;
			         ++p;
						printf("%d\t",*p);
				 }
}
void main()
{
	int a[6]={1,5,8,12,17,25};
	fun1(a);
	fun2(a);
}
#include <stdio.h>
#include <errno.h>
#include<stdlib.h>
extern int  errno;
#define BUFSIZE 1024
void filecopy( FILE* source, FILE *dest )
{
        size_t n,*buf;
        while (0)
        {
                // 1. get character from source file
                n = fread(buf,1,BUFSIZE,source);

                //2. if end-of-file come out of the 
                if (n == 0 )  break;

                // 3. otherwise, put character into dest file
                fwrite(buf,1,n,dest);
        }
}

int catfile(char  *filename)
{
    FILE *infile;

	// open the file for read
    infile = fopen( filename, "r" );  

    if (infile == NULL)
    {
        perror(filename);
		 return 1;
    }

    filecopy( infile, stdout );

    fclose( infile );   // close the file
    return 0;
}

int main(int argc,char *argv[ ])
{
    if (argc == 1)       {
        filecopy(stdin, stdout);
    }
    else   {
        int k;
        for(k=1; k<argc; k++)
        {
             catfile( argv[k] );
        }
    }
    return 0;
}

iiiiiiiiiiiiiiiiiiiiiiii




:iyyyyyyyyy:wq
#include <stdio.h>
#include <errno.h>
extern int  errno;
int n=0;
#define BUFSIZE 1024
/* void filecopy( FILE* source, FILE *dest )
 {
      char *s;
		char buf[BUFSIZE];
  //    printf("%d ",count);
      while (1)
        {
                 // 1. get character from source file
                 s = fgets(buf,BUFSIZE,source);

                //2. if end-of-file come out of the loop
                if (s == NULL)  break;
              // 3. otherwise, put character into dest file
                 fputs(buf, dest);
               //  if((c=='\n') &&( n==1))
               //  printf("%d ",++count);

        }
 }
*/

void filecopy( FILE* source, FILE *dest )
{
        char  c;
		  int count=1;
		   printf("%d ",count);
        while (1)
        {
                // 1. get character from source file
                c = fgetc(source);

                //2. if end-of-file come out of the loop
                if (c == EOF)  break;

                // 3. otherwise, put character into dest file
					 fputc(c, dest);

					 if((c=='\n') &&( n==1))
					 printf("%d ",++count);
               
        }
}

int catfile(char  *filename)
{
    FILE *infile;

	// open the file for read
    infile = fopen( filename, "r" );  

    if (infile == NULL)
    {
        perror(filename);
		 return 1;
    }

    filecopy( infile, stdout );

    fclose( infile );   // close the file
    return 0;
}

int main(int argc,char *argv[ ])
{
//	int n=0;
    if (argc == 1)       {
        filecopy(stdin, stdout);
    }
    else   {
        int k;
//		  if(!strcmp(argv[1],"-n"))
//		  n=1;
        for(k=1; k<argc; k++)
        {
		  		if(!strcmp(argv[1],"-n"))
				{
					 n=1;
					catfile( argv[2 ]);
					k++;

				}
				else
            catfile( argv[k] );
        }
    }
    return 0;
}

#define BUFSIZE 100
int main(int argc, char *argv[])
{
  int fd, spcount, n, k;
  char buf[BUFSIZE+1];
  mkfifo("fifo", 0660);
  fd = open("fifo", O_RDONLY);
  n = read(fd, buf, BUFSIZE);
  buf[n] = 0;
  printf("%s\n", buf);
  spcount = 0;
  for (k=0; k < n; ++k) {
    if (buf[k] == ' ') ++spcount;
  }
  printf("%d\n", spcount);
}
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE	1024

void readfile(int fd)
{
	int n;
	char buf[BUFSIZE];

	while (( n = read(fd, buf, BUFSIZE)) > 0)
	{
		write(1, buf, BUFSIZE);
	}
}

main(int argc, char *argv[])
{
	int fd;

	errno=0;
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		perror(argv[1]);
		return 1;
	}

	if (fd != -1)
	{
		int pid;
		
		pid = fork();
		
		if (pid == -1)
		{

		}
		else if (pid == 0)
		{	
			readfile(fd);
		}
		else
		{

		}
	}

	return 0;
}
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
#include <stdio.h>

long  fact(int n)
{
    long result=1;

    while(n)
    {
        result *= n;
		  n--;
    }
    return result;
}


int main(int argc, char *argv[])
{
	 int n,i;
	 long val;
	 //for(i=1;i<argc;i++){
	 n= atoi(argv[1]);
     val=fact(n);
	 
    printf("%d! = %ld\n", n,val);
	 //}
    return 0;
}
 
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
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *insert(NODE *p,int i)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	if(temp!=NULL)
	{
		temp->data=i;
		temp->next=p;
	}
return temp;
}
void print(NODE *p)
{
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
}
int main()
{
	NODE *head=NULL;
	head=insert(head,5);
	head=insert(head,8);
	head=insert(head,3);
	print(head);
}

#include <malloc.h>
#include <stdio.h>
#include "util.h"


#define ARYSIZE	1	

typedef  struct node
{
	int           data;
	struct node   *next;
} NODE;


static NODE * InsertNode(NODE *p, int n)
{
	NODE *temp;
	temp = (NODE *) malloc(sizeof(NODE));
//	printf("malloc at %u\n", temp);

	if (temp != NULL) 
	{
		temp->data = n;
		temp->next = p;
	}
	return temp;
}


static void PrintList(NODE *head)
{
	NODE *temp = head;

	while ( temp != NULL )
	{
		printf("%d --> ", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

static void DeleteList(NODE* head)
{
	NODE *temp = head;

	while(temp != NULL)
	{
		temp = head->next;
	//	printf("freeing %u \n", head);
		free(head);
		head = temp;
	}
}

// ***********************************************
//  SearchList searches for the specific "val" 
//  in the list pointed by "head"
//  returns :
//        address of the node if it is present
//        otherwise returns NULL
//
static NODE* SearchList(NODE *head, int val)
{
	NODE *temp = head;

	while (temp != NULL)
	{
		if (temp->data == val)
			break;
		temp = temp->next;
	}

	return temp;
}

static void search_for_val(NODE* pHead, int val)
{
	NODE *pNode;

	pNode = SearchList(pHead, val);

	if (pNode != NULL)
	{
		printf("%d found in ll\n", val);
	}
	else
	{
		printf("%d not found in ll\n", val);
	}
}

static void test_ll_search(NODE* head, int a[], int arysize)
{
	int min,max;

	search_for_val(head, a[0]);
	if(arysize!=1)
	{
		search_for_val(head, a[1]);

		search_for_val(head, a[(arysize-1)/2]);

		search_for_val(head, a[arysize-2]);
		search_for_val(head, a[arysize-1]);
	}
	get_min_max(a, arysize, &min, &max);
	printf("max=%d\tmin=%d\n",max,min);
	search_for_val(head, min-1);
	search_for_val(head, max+1);

}

static void test_ll()
{
	NODE *head = NULL;
	int nary[ARYSIZE];
	int   k;

	fill_array_with_rand(nary, ARYSIZE, 1);


	printf("*** creating list\n");
	for( k=0; k< ARYSIZE; k++ )   {
		head = InsertNode( head, nary[  k ] );
	}

	PrintList(head);

	test_ll_search(head, nary, ARYSIZE);

	DeleteList(head);

}

int main()
{
	test_ll();

	return 0;
}






#include <malloc.h>
#include <stdio.h>
#include "util.h"
#include<assert.h>


#define ARYSIZE	5	

typedef  struct node
{
	int           data;
	struct node   *next;
} NODE;


NODE * InsertNode(NODE *p, int n)
{
	NODE *temp;
	temp = (NODE *) malloc(sizeof(NODE));
//	printf("malloc at %u\n", temp);

	if (temp != NULL) 
	{
		temp->data = n;
		temp->next = p;
	}
	return temp;
}


void PrintList(NODE *head)
{
	assert(head!=NULL);
	NODE *temp = head;

	while ( temp != NULL )
	{
		printf("%d --> ", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

void DeleteList(NODE* head)
{
	NODE *temp = head;

	while(temp != NULL)
	{
		temp = head->next;
	//	printf("freeing %u \n", head);
		free(head);
		head = temp;
	}
}

// ***********************************************
//  SearchList searches for the specific "val" 
//  in the list pointed by "head"
//  returns :
//        address of the node if it is present
//        otherwise returns NULL
//
NODE* SearchList(NODE *head, int val)
{
	NODE *temp = head;

	while (temp != NULL)
	{
		if (temp->data == val)
			break;
		temp = temp->next;
	}

	return temp;
}

void search_for_val(NODE* pHead, int val)
{
	NODE *pNode;

	pNode = SearchList(pHead, val);

	if (pNode != NULL)
	{
		printf("%d found in ll\n", val);
	}
	else
	{
		printf("%d not found in ll\n", val);
	}
}

void test_ll_search(NODE* head, int a[], int arysize)
{
	int min,max;

	search_for_val(head, a[0]);
	if(arysize!=1)
	{
		search_for_val(head, a[1]);

		search_for_val(head, a[(arysize-1)/2]);

		search_for_val(head, a[arysize-2]);
		search_for_val(head, a[arysize-1]);
	}
	get_min_max(a, arysize, &min, &max);
	printf("max=%d\tmin=%d\n",max,min);
	search_for_val(head, min-1);
	search_for_val(head, max+1);

}

void test_ll()
{
	NODE *head = NULL;
	int nary[ARYSIZE];
	int   k;

	fill_array_with_rand(nary, ARYSIZE, 1);


	printf("*** creating list\n");
	for( k=0; k< ARYSIZE; k++ )   {
		head = InsertNode( head, nary[  k ] );
	}

	PrintList(NULL);

	test_ll_search(head, nary, ARYSIZE);

	DeleteList(head);

}

int main()
{
	test_ll();

	return 0;
}





	
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
#include <fcntl.h>
#include <sys/mman.h>
int main (int argc, char* argv[])
{
   int fd;
   void* filemap;
   long  filesize;

	 fd = open (argv[1], O_RDONLY);
   // TODO:  get file size saved into the variable filesize
	 filemap = mmap(0, filesize, PROT_READ, MAP_PRIVATE, fd, 0); 
							// map entire file
   close (fd);	// file descriptor no longer needed
	 // TODO: use filemap to write the file content onto the screen
   munmap (filemap, filesize);	// at the end unmap the file
}
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
#include<stdio.h>

void to_word(int n, char *str)
{
	int i;
	for(i=0;i<n;i++)
	{
		switch(ch)
		{
			case u:
				x=0;
				num_word(argv[k][i]);
			case l:	
		}
	}
}

int  main(int argc, char *argv[ ])
   {
        int k;

        for( k=1; k < argc; k++)
        {
            // printf("argv[%d]   %s\t", k, argv[k]);

             if ( argv[k][0] == '-' )
				 		  printf("argv[%d]   %s\tis options\n", k, argv[k]);

                // printf("is an option\n");
            // else
              //   printf("is not an option\n");
         }
         return 0;
    }

#include <stdio.h>
#include <stdlib.h>

int copy_stdin2out()
{


}

int main()
{
  int pd[2], pid;

 pipe(pd);
 pid = fork();

  if (pid == 0) 
  {  // in child
   dup2(pd[0], 0);
    close(pd[1]);
    close(pd[0]);
    copy_stdin2out();
    exit(0);
  }

  else  // in parent 
  {
   dup2(pd[1], 1);
    close(pd[0]);
    close(pd[1]);
    copy_stdin2out();
    wait(NULL);
    exit(0);
  }
}
#include "common.h"

main()
{
  int pd[2];
  int pid;
  pipe(pd);
  pid = fork();
  if (pid == 0)
  {   // in child 
  }
  else
  {   // in parent
     dup2(pd[1], 1);
     close(pd[0]);    
	  close(pd[1]);
	  copy_stdin2stdout();
     wait(NULL);
     exit(0);
  }
} 

 
copy_stdin2stdout()
{
    char buf[100];
    int n;
    while( (n = read(0, buf, 100)) > 0)
         write(1, buf, n);
    close(0);
    close(1);
}


// Code to print the strings one per line using pointers
#include<stdio.h>
int main( )
{
        char *str[ ] = { "C language", "C++ language", "Java" };
        int k;
		  
        int elements =3 ;
		  

        for (k=0; k < elements; k++)
        {
          char *ptr=str[k];
       		puts(ptr);
          putchar('\n');
        }
    return 0;
}

#include<stdio.h>
int main()
{
	if(!str)

}
#include <stdio.h>

struct d
{
   int a;
   float  f;
   char *p;
};

struct d  sd = { 1, 2.5, 0 };

int foo(void *p)
{
    printf("in foo\n");
        return 0;
}

void* dummy(int x)
{
    printf("in dummy x = %d\n",x);
        return 0;
}

main()
{
  int i,a[9] ;
         printf("My first go at the gdb\n") ;
         for( i=0;i<=11; i++ )
         {
 a[i] = i ;
                printf("we are here: %d\n",a[i]);
                dummy(a[i]);
                foo(NULL);
         }
}

#include<stdio.h>
main( int argc, char *argv[ ] )
	{
    	 int k,sum=0;

	    for( k=1; k < argc; k++)
    	{
       		int val;

        	val = atoi( argv[k] );
			sum+=val;
	}
     	printf("sum = %d\n", sum);
     	return 0;
	}

#include <sys/socket.h>		// must for socket apps
#include <netinet/in.h>		// must for socket apps

void transact_with_client(int sock);

main(int argc, char *argv[])
{
    struct sockaddr_in serv, cli;
    int port, sd, nsd;
    port = atoi(argv[1]);
    sd = socket (AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons (port);
    bind (sd, (struct sockaddr*)&serv, sizeof (serv));

  
	 listen (sd, 5);
  	while( 1 )
  {
      int size = sizeof(cli);
      nsd = accept (sd, (struct sockaddr*)&cli, &size);
      transact_with_client(nsd);
      close(nsd);
  }
  close(sd);
}

void transact_with_client(int sock)
{
    char buf[100];
    int  n;

    while ( (n = recv(sock, buf, sizeof(buf), 0)) > 0)
       send(sock, buf, n, 0);
}

     char *p = "hello";
     char buf[ ] = "hello";
     printf("%0X\n", p);

     printf("%0X    %s\n", buf, buf);
     printf("%0X\n", "hello");
	  printf("%0X\n", "Hello");

     *p = 'H';
     printf("%0X\n", p);
     printf("%0X %s\n", buf, buf);
     printf("%0X\n", "hello");
#include<stdio.h>

void main()
{
	int arr[2][2]={1,2,3,4};
	int *p;
	p=arr;
	printf("%d",*p++);
}
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

#include<stdio.h>
void fn_1();
void fn_2();
void fn_3(int p);
void fn_4();
void fn_5(int k);
char *str = "hello";

void fn_1()
{
   int i=1;
   printf("inside fn_1\n");
   fn_2();
}
void fn_2()
{
   int i=2;
char *str = "hello2";
   printf("inside fn_2\n");
   fn_3(i);
}
void fn_3(int p)
{
   int i;
   printf("inside fn_3\n");
   fn_4();
}
void fn_4()
{
char *str = "hello4";
   int i=10;
   printf("inside fn_4\n");
   fn_5(i);
}
void fn_5(int k)
{
   int j=3;
   printf("inside fn_5\n");
}

main()
{
char *str = "world";
    fn_1();
}
#include<stdio.h>
#include<malloc.h>

void zero_1(int n)
{

int	t=1,i;
char *str=(char*)malloc(n*sizeof(char));
	for(i=0;i<n;i++)
	{
		if(t==1)
		{
			str[i]='0';
			t=0;
		}
		else
		{
			str[i]='1';
			t=1;
		}
	}
	str[i]='\0';
	printf("%s\n",str);

}
void main()
{
	int n=10;
	zero_1(n+1);
}
