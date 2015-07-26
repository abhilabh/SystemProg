# include"common.h"
 
  int main()
  {
     int k,shmid,d,i;
     char *data;
     char data1[20];
 
     k=ftok(".",10);
     shmid=shmget(k,1000,0);
     data=shmat(shmid,(void*)0,0);
     printf("%s\n",data);
     d='a'-'A';
//     strcpy(data1,(char*)data);
     for(i=0;i<strlen(data);i++)
     {
      
			data[i]=toupper(data[i]);
     }
//	  sleep(10);
//     strcpy((char*)data,data1);
  // printf("%s\n",data);
     shmdt(data);
 
     exit(0);
  }
