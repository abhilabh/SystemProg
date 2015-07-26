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
