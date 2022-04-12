#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_fun1(void *ptr)
{
	for(int i=0;i<5;i++)
	{
		sleep(2);
		printf("thread1 running\n");
	}
}
void *thread_fun2(void *ptr)
{
	for(int i=0;i<6;i++)
	{
		sleep(2);
		printf("thread2 running\n");
	}
}
int main()
{
	pthread_t thread[2];
	char *msg1="Rakesh";
	char *msg2="thread";
	pthread_create(&thread[0],NULL,&thread_fun1,(void *) msg1);
	pthread_create(&thread[1],NULL,&thread_fun2,(void *) msg2);
	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);
}
