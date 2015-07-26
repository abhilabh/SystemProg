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

