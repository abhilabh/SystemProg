#include"common.h"
struct book
{
	char ibsn[10];
	char name[20];
	int year;
};


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

      char buf[100],bnn[100];
	  struct book *p,b_data[5]={"124","cprograming",2006,"125\n","cprograming2",2007,"126","cprograming3",2002,"127","cprograming4",2009,"129","cprograming5",2000};

      int i,n, size;
	 // struct book b={"124","c_`programing",2006},*p;
	  p=b_data;
	//   sprintf(bnn,"%s %s %d",p->ibsn,p->name,p->year);
      struct sockaddr_in  cliaddr;   // to receive

      size = sizeof(cliaddr);

      while ( 1 )   {

        n = recvfrom(sock, buf,  sizeof(buf), 0,

                       (struct sockaddr*)&cliaddr, &size);
					   buf[4]='\0';
		for(i=0;i<5;i++)
		{
			if(!strcmp(buf,p[i].ibsn))
			{
			sprintf(bnn,"%s %s %d",p[i].ibsn,p[i].name,p[i].year);
			break;
			}

		}

        buf[n]=0;

        if (n <= 0) break;

        size = sizeof(cliaddr);

        n = sendto(sock, bnn, sizeof(buf), 0, (struct

                    sockaddr*)&cliaddr, size);

      }

  }
