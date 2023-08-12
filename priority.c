//Program to implement priority scheduling algorithm
#include <stdio.h>
struct process
{
	int pid;
	int at,bt,ct,wt,tt,prio;
};
void main()
{
	int n,i,j,p,avgwt=0,avgtt=0;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	struct process proc[n];
	printf("\nEnter the pid,burst time,arrival time and priority in order:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&proc[i].pid,&proc[i].bt,&proc[i].at,&proc[i].prio);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(proc[j].at>proc[j+1].at)
				{
					struct process temp=proc[j];
					proc[j]=proc[j+1];
					proc[j+1]=temp;
				}
			}
		}
		int t,b,pos;
		for(i=0;i<n;i++)
		{
			if(i!=0)
			t=proc[i-1].ct;
			else
			t=proc[i].at;
			p=proc[i].prio;
			int t1=t;
			for(j=i;j<n;j++)
			{
				if(proc[j].at<=t1 && proc[j].prio<=p)
				{
					pos=j;
					p=proc[j].prio;
					t1=proc[pos].at;
				}
			}
			proc[pos].ct=t+proc[pos].bt;
			proc[pos].tt=proc[pos].ct-proc[pos].at;
			proc[pos].wt=proc[pos].tt-proc[pos].bt;
			avgwt+=proc[pos].wt;
			avgtt+=proc[pos].tt;
			struct process temp;
			temp=proc[i];
			proc[i]=proc[pos];
			proc[pos]=temp;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(proc[j].pid>proc[j+1].pid){
					struct process temp=proc[j];
					proc[j]=proc[j+1];
					proc[j+1]=temp;
				}
			}
		}
		printf("Pid\tAt\tBt\tCt\tWt\tTt\tPriority\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,
			proc[i].ct,proc[i].wt,proc[i].tt,proc[i].prio);
		}
		printf("\nThe average waiting time =%0.3f\n",(float)avgwt/n);
		printf("\nThe average turnaround time =%0.3f\n",(float)avgtt/n);
	}
