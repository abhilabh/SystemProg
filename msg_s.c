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

  // i++;

  // printf("Enter the mtype :");

  // scanf("%d",&mq.mtype);

  // type[i++]=mq.mtype;

     printf("Enter a name : ");

     scanf(" %[^\n]",mq.name);

     printf("Enter tel no : ");

     scanf("%d", &mq.tel_no);

     msgsnd(msqid,&mq  ,sizeof(mq), 0);

  }

 

  }
