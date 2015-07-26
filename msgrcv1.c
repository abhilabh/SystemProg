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

