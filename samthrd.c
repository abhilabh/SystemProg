#include<pthread.h>
#include<stdio.h>
void* thread_fn()
{
	printf("in the thread %u\n",pthread_self());
	return NULL; //( void*) 0;
}
int main()
{
	pthread_t tid;
	int j,k;
	pthread_create(&tid,NULL,thread_fn,NULL);
	pthread_join(tid,NULL);
	return 0;
}
