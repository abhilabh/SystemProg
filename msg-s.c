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

