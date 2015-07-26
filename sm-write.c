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
