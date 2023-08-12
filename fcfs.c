//Program to implement first come first serve scheduling algorithm
#include <stdio.h>
struct process
{
	int pid;
	int bt;
	int wt;
	int tt;
	int ct;
	int at;
};
void main()
{
	struct process rq[30];
	int num;
	printf("Enter the number of processes:");
	scanf("%d",&num);
	//Input the process
	int i;
	for(i=0;i<num;i++)
	{
		rq[i].pid=i+1;
		int b,a,p;
		printf("Enter the burst time and arrival time in order:");
		scanf("%d %d",&b,&a);
		rq[i].bt=b;
		rq[i].at=a;
	}
	//Sorting based on arrival time using bubble sort
	int j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(rq[j].at>rq[j+1].at)
			{
				struct process temp;
				temp=rq[j];
				rq[j]=rq[j+1];
				rq[j+1]=temp;
			}
		}
	}
	int sum=0;
	for(i=0;i<num;i++)
	{
		sum+=rq[i].bt;
		rq[i].ct=sum;
		rq[i].tt=sum-rq[i].at;
		rq[i].wt=rq[i].tt-rq[i].bt;
	}
	printf("Pid\tBT\tAT\tWT\tTT\tCT\n");
	for(i=0;i<num;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",rq[i].pid,rq[i].bt,rq[i].at,rq[i].wt,rq[i
	].tt,rq[i].ct);
	}
	float avgtt=0,avgwt=0;
	for(i=0;i<num;i++)
	{
		avgtt+=rq[i].tt;
		avgwt+=rq[i].wt;
	}
	printf("The average Tuenaround Time=%0.2f\n",(float)avgtt/num);
	printf("The average Waitnig Time=%0.2f\n",(float)avgwt/num);
}	