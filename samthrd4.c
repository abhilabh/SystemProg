
#include<pthread.h>
#include<stdio.h>
void* thread_fn(void* m)
{
	int *i=(int *)m,k;
	k=*i;
	printf("in the thread %u\n",pthread_self());
	return (void *)k; //( void*) 0;
}
int main()
{
	pthread_t tid,tid1;
	int j=5,k=9;
	void *p,*m;
	pthread_create(&tid,NULL,thread_fn,&j);
	
//	sleep(5);
	pthread_create(&tid1,NULL,thread_fn,&k);
	pthread_join(tid,&p);
	pthread_join(tid1,&m);
	printf("%d \t%d\n",(int)p,(int)m);
	return 0;
}
