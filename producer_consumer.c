//Producer consumer problem using semaphores
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
int buffer[10];
int count=0;
sem_t semEmpty,semFull;
void* producer()
{
	sem_wait(&semEmpty);
	printf("Producer\n");
	while(1)
	{
		int item=count+10;
		if(count==10)
		{
			count--;
			printf("Buffer full\n");
			break;
		}
		else
		{
			buffer[count]=item;
			count++;
			printf("Count after insert:%d\n",count);
		}
		sleep(1);
	}
	sem_post(&semFull);
}
void* consumer()
{
	sem_wait(&semFull);
	printf("Consumer\n");
	while(1)
	{
		if(count==-1)
		{
			printf("Buffer empty\n");
			break;
		}
		else
		{
			int item=buffer[count];
			printf("Item:%d || Index:%d\n",item,count);
			count--;
		}
		sleep(1);
	}
	sem_post(&semEmpty);
}
void main()
{
	sem_init(&semEmpty,0,1);
	sem_init(&semFull,0,0);
	pthread_t arr[2];
	pthread_create(&arr[0],NULL,producer,NULL);
	pthread_create(&arr[1],NULL,consumer,NULL);
	for(int i=1;i<2;i++)
	pthread_join(arr[i],NULL);
	sem_destroy(&semEmpty);
	sem_destroy(&semFull);
}