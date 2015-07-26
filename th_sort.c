#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


struct sortinfo
{
	int *pData;
	int start;
	int end;

};

void* sumarray(void* arg)
{

	int sum=0,k;
	int start=((struct sortinfo*)arg)->start;
	int end=((struct sortinfo*)arg)->end;
	int *data=((struct sortinfo*)arg)->pData;
	bubble_sort(data,start,end);
	return (void *) sum;
}
int bubble_sort(int *a,int start,int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{	
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			
		}
	}
}

void print_arr(int *arr,int start,int size)
{
	int i;
	printf("-------array elements are ----\n");
	for(i=start;i<size;i++)
	printf("%d\t",arr[i]);
	putchar('\n');
}

int main()
{
	time_t t;
	pthread_t tid,tid1,tid2;
	void *status1,*status2,*status3;
	int data[100],data1[100],num=0,i,j;	
	struct sortinfo argval[2] ={data,0,50,data+50,50,50};
	srand(time(NULL));
	for(i=0;i<100;i++)
	{	
		data[i]=(rand()%100);
	}
	print_arr(data,0,100);

	pthread_create(&tid,NULL,&sumarray,&argval[0]);
	pthread_create(&tid1,NULL,&sumarray,&argval[1]);
//	pthread_create(&tid2,NULL,&sumarray,&argval[2]);
	pthread_join(tid,&status1);
	pthread_join(tid1,&status2);
	print_arr(data,0,50);
	print_arr(data,50,100);
	i=0;j=50;
	while(num!=100)
	{
		if(data[i]<data[j])
		{
			data1[num++]=data[i++];

		}
		else
		data1[num++]=data[j++];
	}
	print_arr(data1,0,100);
//	pthread_join(tid2,&status3);
}
