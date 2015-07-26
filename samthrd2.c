
#include<pthread.h>
#include<stdio.h>
void* thread_fn()
{
	printf("in the thread %u\n",pthread_self());
	return NULL; //( void*) 0;
}
int main()
{
	pthread_t tid,tid1;
	int j,k;
	pthread_create(&tid,NULL,thread_fn,NULL);
	
	sleep(5);
	pthread_create(&tid1,NULL,thread_fn,NULL);
	pthread_join(tid,NULL);
	pthread_join(tid1,NULL);
	return 0;
}
