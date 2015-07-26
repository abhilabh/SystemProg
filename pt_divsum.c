#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>


struct arginfo
{
	int *pData;
	int count;

};

void* sumarray(void* arg)
{

	int sum=0,k;
	int n=((struct arginfo*)arg)->count;
	int *data=((struct arginfo*)arg)->pData;
	for(k=0;k<n;k++)
	{
		sum+=data[k];
	}
	return (void *) sum;
}

int main()
{
	time_t t;
	pthread_t tid,tid1,tid2;
	void *status1,*status2,*status3;
	int data[100],i,*p=data;	
	struct arginfo argval[3] ={data,100,data,50,p+50,50};
	srand(time(NULL));
	for(i=0;i<100;i++)
	{	
		data[i]=(rand()%100);
	}
	pthread_create(&tid,NULL,&sumarray,&argval[0]);
	pthread_create(&tid1,NULL,&sumarray,&argval[1]);
	pthread_create(&tid2,NULL,&sumarray,&argval[2]);
	pthread_join(tid,&status1);
	pthread_join(tid1,&status2);
	pthread_join(tid2,&status3);
	printf("sum = %d\n",(int)status1);
	printf("sum by two thread= %d\n",(int)status2+(int)status3);
//	printf("sum sum of remaining= %d\n",(int)status3);
}
