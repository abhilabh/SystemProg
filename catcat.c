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
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int i=0,n;
	int fd1,fd2;
	char buf[50];
	fd1=open("cat.c",O_RDWR);
	while(1)
	{
		
		n=read(fd1,buf,50);
		if(n<=0)
		break;
	//	printf("%d",n);
		write(1,buf,n);
	}	
//	if(argc==2)
close(fd1);
}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void filecp(int source,int dest)
{
	int n;
	char buf[50];
	while(1)
	{
		
		n=read(source,buf,50);
		if(n<=0)
		break;
	//	printf("%d",n);
		write(dest,buf,n);
	}	
}
void filecopy()
{
	int fd1,fd2;
	fd1=open("cat.c",O_RDWR);
	fd2=open("ccc",O_RDWR);
	filecp(fd1,fd2);
//	printf("%d %d",fd1,fd2);
	close(fd1);
	close(fd2);
}

int main()
{
	int i=0;
//	if(argc==2)
	filecopy();
}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int m=0;

void filecp(int source,int dest)
{
	int n;
	char buf[51];
	while(1)
	{
		
		n=read(source,buf,50);
		if(n<=0)
		break;
	//	printf("%d",n);
		write(dest,buf,n);
	}	
}
void filecopy(char *filename1,char *filename2)
{
	int fd1,fd2;
	fd1=open(filename1,O_RDWR);
//	if(m=0)
		fd2=open(filename2,O_CREAT | O_EXCL);
//	else
//		fd2=open(filename2,O_CREAT | O_RDWR );
		filecp(fd1,fd2);
	close(fd1);
	close(fd2);
}

int main(int argc,char *argv[])
{
	int i=0;
	if(argc==3)
	{
		//m=1;
		filecopy(argv[1],argv[2]);
	}
	else
	{
	//	if(argc>3)
		if(!strcmp(argv[1],"-l"))
		{
			m=1;
			filecopy(argv[2],argv[3]);
		}
	}
}
#include <stdio.h>  /* for perror() */
#include <stdlib.h> /* for exit() */

void DieWithError(char *errorMessage)
{
    perror(errorMessage);
    exit(1);
}

#include"common.h"
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
#include"common.h"
#define BUFSIZE 100

 int main(int argc, char *argv[])

  {

    int fd,fd1, spcount, n, k;

    char buf[BUFSIZE+1];
	
	fd1=open("cat.c",O_RDONLY);
	n=read(fd1,buf,BUFSIZE);

    mkfifo("fifo", 0660);

    fd = open("fifo", O_WRONLY);

     write(fd, buf, n);

//    buf[n] = 0;

//    printf("%s\n", buf);

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
#include <fcntl.h>
#include <sys/mman.h>
#include"common.h"
int main (int argc, char* argv[])
{
   int fd;
   void* filemap;
   long  filesize;
	struct stat st_stat;

	 fd = open (argv[1], O_RDONLY);
   // TODO:  get file size saved into the variable filesize
	fstat(fd,&st_stat);
	filesize=st_stat.st_size;
	 filemap = mmap(0, filesize, PROT_READ, MAP_PRIVATE, fd, 0); 
							// map entire file
   close (fd);	// file descriptor no longer needed
	 // TODO: use filemap to write the file content onto the screen
	 write(1,filemap,filesize);
   munmap (filemap, filesize);	// at the end unmap the file
}
#include "common.h"
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_queue
{
	long mtype;
	char name[20];
	int tel_no;
};

int type[20];

int main(int argc, char *argv[])
{
	struct msg_queue mq;
	int key,msqid,i=0, ret;
	int mtype = atoi(argv[1]);
	key = ftok(".", 'A');
	msqid=msgget(key, 0);

	while(1)  {
		msgrcv(msqid,&mq, sizeof(mq), mtype, 0);
		printf("type %d  %20s   %d\n", 
				mq.mtype, mq.name, mq.tel_no);	
	}

	return 0;
}

#include<sys/msg.h>
#include"common.h"
struct msg_queue
{
  long mtype;
  char name[20];
  int tel_no;
};

int main()
{
	struct msg_queue mq;
	int key,msqid,i=0,k;
	key = ftok(".",'A');
	msqid=msgget(key,0);
	while(1)
	{
	//	i++;
		msgrcv(msqid,&mq,sizeof(mq),0,IPC_NOWAIT);
	
	//	while(k<=0){};
		printf("Name : %s\n",mq.name);
		printf("Tel. number : %d\n",mq.tel_no);
	}
	
}

#include "common.h"
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_queue
{
	long mtype;
	char name[20];
	int tel_no;
};

int type[20];

int main()
{
	struct msg_queue mq;
	int key,msqid,i=0, ret;
	struct msqid_ds buf;
	key = ftok(".", 'A');
	msqid=msgget(key, IPC_CREAT|0666);
	printf("msg key = %08x  id = %d\n", key, msqid);
	msgctl(msqid, IPC_STAT, &buf);

	while(1)  {
		ret = scanf("%d",&mq.mtype);
		if (ret == EOF) break;
		scanf(" %[^\n]",mq.name);
		scanf("%d", &mq.tel_no);
		printf("sending msg %d %s %d\n", 
					mq.mtype, mq.name, mq.tel_no);
		msgsnd(msqid,&mq, sizeof(mq), 0);
		msgctl(msqid, IPC_STAT, &buf);
	}

	return 0;
}

#include"common.h"
#include<sys/ipc.h>
#include<sys/msg.h>
 struct msg_queue
{
 long mtype;
 char name[20];
 int tel_no;
};
//int type[20];

int main()
{
	struct msg_queue mq;
	int key,msqid,i=0;
   key = ftok(".", 'A');
	msqid=msgget(key,IPC_CREAT|0666);

	while(1)  {
//	i++;
//	printf("Enter the mtype :");
//	scanf("%d",&mq.mtype);
//	type[i++]=mq.mtype;
	printf("Enter a name : ");
	scanf(" %[^\n]",mq.name);
	printf("Enter tel no : ");
	scanf("%d", &mq.tel_no);
	msgsnd(msqid,&mq	,sizeof(mq), 0);
}

}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFSIZE 100
int main(int argc,char *argv[])
{
	int fd,pid,n;
//	int n;
	char buf[BUFSIZE];
	fd=open(argv[1],O_RDONLY);
//	pid=fork();
	if((pid=fork())==-1)
	{
		printf("fork fails");
	}
	if(pid==0)
	{
	//	printf("in child --%d--",fd);
		while(1)
		{
			n=read(fd,buf,BUFSIZE);
			if(n<=0)
			break;
			write(1,buf,n);
		}
	}
	if(pid>0)
	close(fd);
	return 0;

}
#include <stdio.h>
#include <string.h>

#define BUFSIZE	100
int main()
{
    int     n;
    int     fd[2];
    int   	pid;
	 char 	*msg="one line of text\n";
    char    line[BUFSIZE];
    char    buf2[BUFSIZE*2];

    pipe(fd);
    pid = fork();

    if (pid > 0) 
	 { 
	 	printf("created child -- %d\n", pid);
        close(fd[0]);
        write(fd[1], msg, strlen(msg));
    } 
	 else if (pid == 0)
	 {                
        int n;
		  close(fd[1]);
        n = read(fd[0], line, BUFSIZE);
		  n = sprintf(buf2, "pid - %d - %s\n", getpid(), line);
        write(1, buf2, n);
    }
    return(0);
}


#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
//	char buf[BUFSIZE];
//int n;

int copy_stdin2out()
{
int n;
char buf[BUFSIZE];
	
	while((n=read(1,buf,BUFSIZE))>0)
	{
		
		write(0,buf,n);
	}

}

int main()
{
  int pd[2], pid;

 pipe(pd);
 pid = fork();

  if (pid == 0) 
  {  // in child
   dup2(pd[1], 0);
    close(pd[0]);
    close(pd[1]);
    copy_stdin2out();
    exit(0);
  }

  else  // in parent 
  {
   dup2(pd[0], 1);
    close(pd[1]);
    close(pd[0]);
	 //sleep(5);
	// wait();
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
  {
  // in child 
     dup2(pd[0], 0);
     close(pd[1]);    
	  close(pd[0]);
	  copy_stdin2stdout();
    // doparent();
    // wait(NULL);
    // exit(0);
  		
  }
  else
  {   // in parent
     dup2(pd[1], 1);
     close(pd[0]);    
	  close(pd[1]);
	  copy_stdin2stdout();
//     doparent();
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

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int pd[2],pid;
	pipe
}

void print_sock_info(int sock)
{
	struct sockaddr_in saddr;
	int  size = sizeof(saddr);
	getsockname(sock,(struct sockaddr*)&saddr,&size);
	printf("FAMILY    =%d\n",saddr.sin_family);
	printf("scr IP    =%s\n",inet_ntoa(saddr.sin_addr));
	printf("src          port           =         %d\n",(int)ntohs(saddr.sin_port));
	
	
	getpeername(sock,(struct sockaddr*)&saddr,&size);
	printf("FAMILY    =%d\n",saddr.sin_family);
	printf("scr IP    =%s\n",inet_ntoa(saddr.sin_addr));
	printf("src          port           =         %d\n",(int)ntohs(saddr.sin_port));
}
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/types.h>
#include <linux/ipc.h>
#include <linux/sem.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  key_t key;
  int semid;
  union semun arg;
  struct sembuf lock_res = {0, -1, 0};
  struct sembuf rel_res = {0, 1, 0};
  struct sembuf push[2] = {1, -1, IPC_NOWAIT, 2, 1, IPC_NOWAIT};
  struct sembuf pop[2] = {1, 1, IPC_NOWAIT, 2, -1, IPC_NOWAIT};

  int i;

  if(argc < 2){
    exit(0);
  }

  key = ftok("/etc/fstab", getpid());

  semid = semget(key, 3, 0666 | IPC_CREAT);

  arg.val = 1;
  semctl(semid, 0, SETVAL, arg);

  arg.val = atol(argv[1]);
  semctl(semid, 1, SETVAL, arg);

  arg.val = 0;
  semctl(semid, 2, SETVAL, arg);

  for (i = 0; i < 5; i++){
    pid = fork();
    if (!pid){
      for (i = 0; i < 20; i++){
	sleep(rand()%6);
	if (semop(semid, &lock_res, 1) == -1){
	  perror("semop:lock_res");
	}
	if (semop(semid, &push, 2) != -1){
	  printf("---> Process:%d\n", getpid());
	}
	else{
	  printf("---> Process:%d  BUFFER FULL\n", getpid());
	}
	semop(semid, &rel_res, 1);
      }
      exit(0);
    }
  }

  for (i = 0;i < 100; i++){
    sleep(rand()%3);
    if (semop(semid, &lock_res, 1) == -1){
      perror("semop:lock_res");
    }
    if (semop(semid, &pop, 2) != -1){
      printf("<--- Process:%d\n", getpid());
    }
    else printf("<--- Process:%d  BUFFER EMPTY\n", getpid());
    semop(semid, &rel_res, 1);
  }

  semctl(semid, 0, IPC_RMID);

  return 0;
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "semlib.h"


int initsem(int flag)
{
  union semun  semarg;
  int			  id;
  key_t		  key;

  if (flag == 1)  {
    key = ftok(".", 'Z');
    id = semget(key, 1, 0666 | IPC_CREAT);
    semarg.val = 1;
    semctl(id, 0, SETVAL, semarg);
//	 semarg.val = 2;
//	 semctl(id,1,SETVAL);
  }
  else  {
    key = ftok(".", 'Z');
    id = semget(key, 1, 0);
  }
  return id;
}

int getsem(int semid)
{
   struct sembuf  sembuf[ ] = { 0, -1, 0 };
   int retval; 

   retval = semop(semid, sembuf, 1);
   return retval;
}

int releasesem(int semid)
{
	struct sembuf sembuf[ ] = { 0, 1, 0 };
	int retval; 

	retval = semop(semid, sembuf, 1);
	return retval;
}
#include<stdio.h>

int main(int argc, char *argv[])
{
   int semid;
   semid = initsem(atoi(argv[1])); 
   while (1)
  {
    printf("press ENTER to acquire sem\n");
    getc(stdin);
    printf("acquiring sem ...\n");
    getsem(semid);
    printf("acquired sem ...\n");
    printf("press ENTER to release sem\n");
    getc(stdin);
    releasesem(semid);
    printf("released sem\n");
  }
}
#include"common.h"

int main()
{
	int k,shmid,d,i;
	void* data;
	char data1[20];
	
	k=ftok(".",10);
	shmid=shmget(k,1000,0);
	data=shmat(shmid,(void*)0,0);
	printf("%s\n",data);
	d='a'-'A';
	strcpy(data1,(char*)data);
	for(i=0;i<strlen(data1);i++)
	{	
		data1[i]=data1[i]-d;
	}	
	strcpy((char*)data,data1);
//	printf("%s\n",data);
	shmdt(data);
	
	exit(0);
}
# include"common.h"
 
  int main()
  {
     int k,shmid,d,i;
     char *data;
     char data1[20];
 
     k=ftok(".",10);
     shmid=shmget(k,1000,0);
     data=shmat(shmid,(void*)0,0);
     printf("%s\n",data);
     d='a'-'A';
//     strcpy(data1,(char*)data);
     for(i=0;i<strlen(data);i++)
     {
      
			data[i]=toupper(data[i]);
     }
//	  sleep(10);
//     strcpy((char*)data,data1);
  // printf("%s\n",data);
     shmdt(data);
 
     exit(0);
  }
 #include"common.h"

 int main()
 {
    int k,shmid;
    char *data;

    k=ftok(".",10);
    shmid=shmget(k,1000,IPC_CREAT|0744);
	 printf("%x %d\n", k,shmid);
    data=shmat(shmid,(void*)0,0);
	 strcpy(data,"hello world");
	 sleep(10);
    printf("%s\n",data);
    shmdt(data);
    exit(0);
 }
 #include <sys/socket.h>    // must for socket apps
 #include <netinet/in.h>    // must for socket apps
 #include"common.h"
 
 void transact_with_serv(int sock);

 main(int argc, char *argv[])
 {
     struct sockaddr_in serv;
     int port, sd;
     port = atoi(argv[2]);
     sd = socket (AF_INET, SOCK_STREAM, 0);
	  memset(&serv,0,sizeof(struct sockaddr_in));
     serv.sin_family = AF_INET;
     serv.sin_addr.s_addr = inet_addr(argv[1]);
     serv.sin_port = htons (port);
     connect (sd, (struct sockaddr*)&serv, sizeof (serv));


   transact_with_serv(sd);
   close(sd);
 }
 void transact_with_serv(int sock)
 {
     char buf[100];
     int  n;
   
	 // while(1)
//	  {
	//  bzero(buf,sizeof(buf));
	 // fgets(buf,sizeof(buf)-1,stdin);
    // send(sock, buf, strlen(buf), 0);
     n = recv(sock, buf, sizeof(buf), 0);
     write(1,buf,n);
	  //}
 }
														  
 #include <sys/socket.h>    // must for socket apps
 #include <netinet/in.h>    // must for socket apps
 #include"common.h"
 
 void transact_with_serv(int sock);

 main(int argc, char *argv[])
 {
     struct sockaddr_in serv;
     int port, sd;
     port = atoi(argv[2]);
     sd = socket (AF_INET, SOCK_STREAM, 0);
	  memset(&serv,0,sizeof(struct sockaddr_in));
     serv.sin_family = AF_INET;
     serv.sin_addr.s_addr = inet_addr(argv[1]);
     serv.sin_port = htons (port);
     connect (sd, (struct sockaddr*)&serv, sizeof (serv));


   transact_with_serv(sd);
   close(sd);
 }
 void transact_with_serv(int sock)
 {
     char buf[100];
     int  n;
   
	  while(1)
	  {
	  bzero(buf,sizeof(buf));
	  fgets(buf,sizeof(buf)-1,stdin);
     send(sock, buf, strlen(buf), 0);
     n = recv(sock, buf, sizeof(buf), 0);
     write(1,buf,n);
	  }
 }
														  
#include <sys/socket.h>		// must for socket apps
#include <netinet/in.h>		// must for socket apps
#include"common.h"
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
	 {
	 write(1,buf,n);
       send(sock, buf, n, 0);
		 }
}

#include <sys/socket.h>		// must for socket apps
#include <netinet/in.h>		// must for socket apps
#include"common.h"
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
      int pid,size = sizeof(cli);
      nsd = accept (sd, (struct sockaddr*)&cli, &size);
		pid=fork();
		if(pid==0)
		{
			close(sd);
      	transact_with_client(nsd);
			close(nsd);
			exit(0);
		}
		else
		close(nsd);
  }
  close(sd);
}

void transact_with_client(int sock)
{
    char buf[100];
    int  n;

    while ( (n = recv(sock, buf, sizeof(buf), 0)) > 0)
	 {
	 write(1,buf,n);
	 bzero(buf,sizeof(buf));
	 fgets(buf,sizeof(buf)-1,stdin);
       send(sock, buf, n, 0);
		 }
}

#include"common.h"
void transact_with_server(int sock,char *servIP,int port);
int main(int argc, char *argv[])
{
  int port, sd, nsd;

  sd = socket (AF_INET, SOCK_DGRAM, 0);
 
  port = atoi(argv[2]);
  transact_with_server(sd, argv[1], port);

  close(sd);
  return 0;
}

void transact_with_server(int sock, 
						char *servIP, int port)
{
    char buf[100];
    int  n, size;
    struct sockaddr_in servaddr;
    memset((char *) &servaddr, 0, 
			sizeof(servaddr)); 
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons (port);
    inet_aton(servIP, &servaddr.sin_addr);
    size = sizeof(servaddr);

   while ( 1 ) {
      bzero(buf, sizeof(buf));
      fgets(buf, sizeof(buf)-1, stdin);
      n = strlen(buf);
      buf[n]=0;
      size = sizeof(servaddr);
      n = sendto(sock, buf, n, 0, 
					(struct sockaddr*)&servaddr, size);
      size = sizeof(servaddr);
      n = recvfrom(sock, buf,  sizeof(buf), 0, 
					(struct sockaddr*)&servaddr, &size);
      if (n <= 0) break;
      else
        write(1, buf, n);
   }
}

 
#include"common.h"
void transact_with_server(int sock,char *servIP,int port);
int main(int argc, char *argv[])
{
  int port, sd, nsd;

  sd = socket (AF_INET, SOCK_DGRAM, 0);
 
  port = atoi(argv[2]);
  transact_with_server(sd, argv[1], port);

  close(sd);
  return 0;
}

void transact_with_server(int sock, 
						char *servIP, int port)
{
    char buf[100];
    int  n, size;
    struct sockaddr_in servaddr;
    memset((char *) &servaddr, 0, 
			sizeof(servaddr)); 
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons (port);
    inet_aton(servIP, &servaddr.sin_addr);
    size = sizeof(servaddr);

   while ( 1 ) {
      bzero(buf, sizeof(buf));
      fgets(buf, sizeof(buf)-1, stdin);
      n = strlen(buf);
      buf[n]=0;
      size = sizeof(servaddr);
      n = sendto(sock, buf, n, 0, 
					(struct sockaddr*)&servaddr, size);
      size = sizeof(servaddr);
      n = recvfrom(sock, buf,  sizeof(buf), 0, 
					(struct sockaddr*)&servaddr, &size);
      if (n <= 0) break;
      else
        write(1, buf, n);
   }
}

 
#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), sendto(), and recvfrom() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define ECHOMAX 255     /* Longest string to echo */

void DieWithError(char *errorMessage);  /* External error handling function */

int main(int argc, char *argv[])
{
    int sock;                        /* Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    struct sockaddr_in fromAddr;     /* Source address of echo */
    unsigned short echoServPort;     /* Echo server port */
    unsigned int fromSize;           /* In-out of address size for recvfrom() */
    char *servIP;                    /* IP address of server */
    char *echoString;                /* String to send to echo server */
    char echoBuffer[ECHOMAX+1];      /* Buffer for receiving echoed string */
    int echoStringLen;               /* Length of string to echo */
    int respStringLen;               /* Length of received response */

    if ((argc < 3) || (argc > 4))    /* Test for correct number of arguments */
    {
        fprintf(stderr,"Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }

    servIP = argv[1];           /* First arg: server IP address (dotted quad) */
    echoString = argv[2];       /* Second arg: string to echo */

    if ((echoStringLen = strlen(echoString)) > ECHOMAX)  /* Check input length */
        DieWithError("Echo word too long");

    if (argc == 4)
        echoServPort = atoi(argv[3]);  /* Use given port, if any */
    else
        echoServPort = 7;  /* 7 is the well-known port for the echo service */

    /* Create a datagram/UDP socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct the server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));    /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                 /* Internet addr family */
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);  /* Server IP address */
    echoServAddr.sin_port   = htons(echoServPort);     /* Server port */

    /* Send the string to the server */
    if (sendto(sock, echoString, echoStringLen, 0, (struct sockaddr *)
               &echoServAddr, sizeof(echoServAddr)) != echoStringLen)
        DieWithError("sendto() sent a different number of bytes than expected");
  
    /* Recv a response */
    fromSize = sizeof(fromAddr);
    if ((respStringLen = recvfrom(sock, echoBuffer, ECHOMAX, 0, 
         (struct sockaddr *) &fromAddr, &fromSize)) != echoStringLen)
        DieWithError("recvfrom() failed");

    if (echoServAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr)
    {
        fprintf(stderr,"Error: received a packet from unknown source.\n");
        exit(1);
    }

    /* null-terminate the received data */
    echoBuffer[respStringLen] = '\0';
    printf("Received: %s\n", echoBuffer);    /* Print the echoed arg */
    
    close(sock);
    exit(0);
}


#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket() and bind() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define ECHOMAX 255     /* Longest string to echo */

void DieWithError(char *errorMessage);  /* External error handling function */

int main(int argc, char *argv[])
{
    int sock;                        /* Socket */
    struct sockaddr_in echoServAddr; /* Local address */
    struct sockaddr_in echoClntAddr; /* Client address */
    unsigned int cliAddrLen;         /* Length of incoming message */
    char echoBuffer[ECHOMAX];        /* Buffer for echo string */
    unsigned short echoServPort;     /* Server port */
    int recvMsgSize;                 /* Size of received message */

    if (argc != 2)         /* Test for correct number of parameters */
    {
        fprintf(stderr,"Usage:  %s <UDP SERVER PORT>\n", argv[0]);
        exit(1);
    }

    echoServPort = atoi(argv[1]);  /* First arg:  local port */

    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct local address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));   /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                /* Internet address family */
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    echoServAddr.sin_port = htons(echoServPort);      /* Local port */

    /* Bind to the local address */
    if (bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("bind() failed");
  
    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        cliAddrLen = sizeof(echoClntAddr);

        /* Block until receive message from a client */
        if ((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0,
            (struct sockaddr *) &echoClntAddr, &cliAddrLen)) < 0)
            DieWithError("recvfrom() failed");

        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

        /* Send received datagram back to the client */
        if (sendto(sock, echoBuffer, recvMsgSize, 0, 
             (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr)) != recvMsgSize)
            DieWithError("sendto() sent a different number of bytes than expected");
    }
    /* NOT REACHED */
}


#include"common.h"
struct
void transact_with_client(int sock);
main(int argc, char *argv[ ])
{
    struct sockaddr_in serv, cli;
    int port, sd, nsd;
    port = atoi(argv[1]);
    sd = socket (AF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons (port);
    bind (sd, (struct sockaddr*)&serv, sizeof (serv));
    transact_with_client(sd);
    close(sd);
}

void transact_with_client(int sock)
{
    char buf[100];
    int  n, size;
    struct sockaddr_in  cliaddr;   // to receive 
    size = sizeof(cliaddr);
    while ( 1 )   {
		n = recvfrom(sock, buf,  sizeof(buf), 0, 
							(struct sockaddr*)&cliaddr, &size);
      buf[n]=0;
      if (n <= 0) break;
      size = sizeof(cliaddr);
      n = sendto(sock, buf, n, 0, (struct 
						sockaddr*)&cliaddr, size);
    }
}

#include"common.h"
void transact_with_client(int sock);
main(int argc, char *argv[ ])
{
    struct sockaddr_in serv, cli;
    int port, sd, nsd;
    port = atoi(argv[1]);
    sd = socket (AF_INET, SOCK_DGRAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons (port);
    bind (sd, (struct sockaddr*)&serv, sizeof (serv));
    transact_with_client(sd);
    close(sd);
}

void transact_with_client(int sock)
{
    char buf[100];
    int  n, size;
    struct sockaddr_in  cliaddr;   // to receive 
    size = sizeof(cliaddr);
    while ( 1 )   {
		n = recvfrom(sock, buf,  sizeof(buf), 0, 
							(struct sockaddr*)&cliaddr, &size);
      buf[n]=0;
      if (n <= 0) break;
      size = sizeof(cliaddr);
      n = sendto(sock, buf, n, 0, (struct 
						sockaddr*)&cliaddr, size);
    }
}

