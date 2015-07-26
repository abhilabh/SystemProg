#include<stdio.h>
#include<pthread.h>

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
	pthread_t tid;
	void *status;
	int data[5]={5,17,19,12,15};
	struct arginfo argval ={data,5};
	pthread_create(&tid,NULL,&sumarray,&argval);
	pthread_join(tid,&status);
	printf("status = %d\n",(int)status);
}
