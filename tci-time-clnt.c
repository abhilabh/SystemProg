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
   
	 while(( n = recv(sock, buf, sizeof(buf), 0))>0)
	  {
 	 //bzero(buf,sizeof(buf));
	 //fgets(buf,sizeof(buf)-1,stdin);
     //send(sock, buf, strlen(buf), 0);
     write(1,buf,n);
	 }
 }
														  
