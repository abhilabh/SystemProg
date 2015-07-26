
#include<pthread.h>
#include<stdio.h>
void* thread_fn()
{
	printf("in the thread %u\n",pthread_self());
	return (void *)3; //( void*) 0;
}
void* thread_fn1()
{
	printf("in the thread %u\n",pthread_self());
	return (void *)7; //( void*) 0;
}
int main()
{
	pthread_t tid,tid1;
	int j,k;
	void *ret;
	pthread_create(&tid,NULL,thread_fn,NULL);
	pthread_join(tid,&ret);
	printf("%d\n",(int *)ret);
	pthread_create(&tid1,NULL,thread_fn1,NULL);
	pthread_join(tid,&ret);
	printf("%d\n",(int *)ret);
	return 0;
}
