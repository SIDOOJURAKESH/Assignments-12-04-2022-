#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("parent process exicuted suceesfully:%d\n",getpid());
		exit(0);
	}
	else if(pid==0)
	{
		sleep(5);//orphan process
		printf("child process exicute succesfully:%d\n",getpid());
	}
	else
	{
		printf("child process cannot created succesfully\n");
	}
}
