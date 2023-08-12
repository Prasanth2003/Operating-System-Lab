//Interprocess communication Writer
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
void main()
{
	void* sm;
	char buff[30];
	int shmid;
	shmid=shmget((key_t)1234,2048,0666|IPC_CREAT);
	printf("\nShared Memory ID is:%d\n",shmid);
	sm=shmat(shmid,NULL,0);
	printf("\nMemory attained at %p",sm);
	read(0,buff,21);
	strcpy(sm,buff);
	printf("\nMessage written is:%s",(char*)sm);
	shmdt(sm);
}