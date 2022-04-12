#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	getchar();
	pid = fork();

	if(pid == -1)
	perror("fork fails");

	if(pid == 0)
	{
		//sleep(1);
		printf("children process pid:%d\n",getpid());
		printf("children process parent pid:%d\n",getppid());

	}
	else
	{
		//sleep(2);
		printf("parent process pid:%d\n",getpid());
		printf("parent process parent pid:%d\n",getppid());
	}

return 0;
}
