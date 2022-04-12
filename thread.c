#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define n 8

void *myfun()//Thread Handling Function
{
	unsigned int i;
	for(i=0;i<=n;i++)
	{
		sleep(1);
		printf("Thread1 is printing\n");
	}
}

int main()
{
	pthread_t newthread;
	pthread_create(&newthread,NULL,&myfun,NULL);
	pthread_join(newthread,NULL);
	return 0;
}
