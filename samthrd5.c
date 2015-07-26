
#include<pthread.h>
#include<stdio.h>
void* thread_fn(int *ret)
{
	
	printf("in the thread %u\n",pthread_self());
	return ret; //( void*) 0;
}
void* thread_fn1()
{
	printf("in the thread %u\n",pthread_self());
	return NULL; //( void*) 0;
}
int main()
{
	pthread_t tid,tid1;
	int j=4,k=1;
	void *p=(int *)&j,*q=(int *)&k;
	int **ret;
	printf("%d",**ret);
	pthread_create(&tid,NULL,thread_fn,p);
	
//	sleep(5);
	pthread_create(&tid1,NULL,thread_fn,q);
	pthread_join(tid,(int *)ret);
	printf("%d",**ret);
	pthread_join(tid1,(int *)ret);
	printf("%d",**ret);
	return 0;
}
