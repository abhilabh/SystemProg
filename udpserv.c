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
