#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>


struct arginfo
{
	int *pData;
	int start;
	int end;

};

void* prime(void* arg)
{

	int sum=0,k,num,j,s=0;
	int start=((struct arginfo*)arg)->start;
	int end =((struct arginfo*)arg)->end;
	int *data=((struct arginfo*)arg)->pData;
	num=start/2;
	for(k=start+1;k<end;k++)
	{
		if(isprime(k))
		//printf("%d prime num \t",k);
		data[num++]=k;
	}
	return (void *) num;
}
int isprime(int num)
{
	int j;
	
		for(j=2;j<=num/2;j++)
		{
			if(num%j!=0)
			continue;
			else
			return 0;
		}
		return 1;
}

int main()
{
	time_t t;
//	int j;
	pthread_t tid,tid1,tid2,tid3;
	void *status1,*status2,*status3,*status4;
	int data[500],i,*p=data;	
	struct arginfo argval[4] ={data,0,200,data,201,400,data,401,600,data,601,1000};/*,data,50,p+50,50};*/
	srand(time(NULL));
	
	pthread_create(&tid,NULL,&prime,&argval[0]);
	pthread_create(&tid1,NULL,&prime,&argval[1]);
	pthread_create(&tid2,NULL,&prime,&argval[2]);
	pthread_create(&tid3,NULL,&prime,&argval[3]);
	pthread_join(tid,&status1);
	pthread_join(tid1,&status2);
	pthread_join(tid2,&status3);
	pthread_join(tid3,&status4);
	printf("%d\t%d\t%d\t%d\t",(int)status1,(int)status2,(int)status3,(int)status4);
	for(i=0;i<(int)status1;i++)
	printf("%d\t",data[i]);
	for(i=100;i<(int)status2;i++)
	printf("%d\t",data[i]);
	for(i=200;i<(int)status3;i++)
	printf("%d\t",data[i]);
	for(i=300;i<(int)status4;i++)
	printf("%d\t",data[i]);
}
