//Program to demonstrate execv
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main()
{
	pid_t p;
	printf("Before fork\n");
	p=fork();
	if(p==0)
	{
		printf("Chlid id:%d\n",getpid());
		printf("Parent id:%d\n",getppid());
	}
	else
	{
		sleep(10);
		printf("Child id:%d\n",p);
		printf("Parent id:%d\n",getpid());
	}
	char *args[]={NULL};
	execv("./hello",args);
}
		