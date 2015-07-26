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

