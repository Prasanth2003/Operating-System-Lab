//Program to implement SJF scheduling algorithm
#include <stdio.h>
struct process
{
	int pid;
	int at,bt,ct,wt,tt;
};
void main()
{
	int n,i,j,avgwt=0,avgtt=0;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	struct process proc[n];
	printf("\nEnter the pid,arrival time,burst time in order:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&proc[i].pid,&proc[i].at,&proc[i].bt);
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
		b=proc[i].bt;
		for(j=i;j<n;j++)
		{
			if(proc[j].at<=t && proc[j].bt<=b)
			{
				pos=j;
				b=proc[j].bt;
			}
		}
		proc[pos].ct=t+b;
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
		if(proc[j].pid>proc[j+1].pid)
		{
		struct process temp=proc[j];
		proc[j]=proc[j+1];
		proc[j+1]=temp;
		}
		}
		}
		printf("Pid\tAt\tBt\tCt\tWt\tTt\n");
		for(i=0;i<n;i++)
		{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,proc
		[i].ct,proc[i]. wt,proc[i].tt);
		}
		printf("\nThe average waiting time =%0.3f\n",(float)avgwt/n);
		printf("\nThe average turnaround time =%0.3f\n",(float)avgtt/n);
		}		