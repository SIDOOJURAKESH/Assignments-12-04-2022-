#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
char ch = 65;
pthread_mutex_t mutex;
void* capital(void *ptr)
{
        pthread_mutex_lock(&mutex);
        while(ch <= 90)
        {
                printf("%c\n",ch);
                ch++;
                sleep(1);
        }
        ch =65;
         pthread_mutex_unlock(&mutex);
}
void* small(void *ptr)
{
        pthread_mutex_lock(&mutex);
        while(ch <= 90)
        {
                printf("%c\n",ch+32);
                ch++;
                sleep(1);
        }
         pthread_mutex_unlock(&mutex);
}
int main(void)
{
     pthread_t newthread[2];
     pthread_mutex_init(&mutex,NULL);
     pthread_create(&newthread[0],NULL,&capital,NULL);
     pthread_create(&newthread[1],NULL,&small,NULL);
     pthread_join(newthread[0],NULL);
     pthread_join(newthread[1],NULL);
     pthread_mutex_destroy(&mutex);
     return 0;
}
