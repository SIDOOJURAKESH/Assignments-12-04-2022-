#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <semaphore.h>
#include <unistd.h>


int ch=65;
sem_t sem;

void *upper(void *args)
{
	sem_wait(&sem);
	while(ch<=90)
	{
		printf("Upper:%c\n",ch);
		ch++;
	}
	ch=65;
	sem_post(&sem);
}
void *lower(void *args)
{
	sem_wait(&sem);
	while(ch<=90)
	{
		printf("lower:%c\n",ch+32);
		ch++;
	}
	sem_post(&sem);
}
int main()
{
	sem_init(&sem,0,2);
	pthread_t a_thread[2];
	pthread_create(&a_thread[0],NULL,upper,NULL);
	pthread_create(&a_thread[1],NULL,lower,NULL);
	pthread_join(a_thread[0],NULL);
	pthread_join(a_thread[1],NULL);
	sem_destroy(&sem);
	return 0;	
}
		
