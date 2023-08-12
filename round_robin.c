//Program to implement RoundRobin scheduling algorithm
#include <stdio.h>
struct process
{
	int pid;
	int at,bt,ct,wt,tt;
};
void main()
{
	int n,i,j;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	struct process proc[n];
	for(i=0;i<n;i++)
	{
		proc[i].pid=i+1;
		printf("\nEnter the burst time,arrival time in order:");
		scanf("%d %d",&proc[i].bt,&proc[i].at);
	}
	int q;
	printf("\nEnter the time quantum:");
	scanf("%d",&q);
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
	int temp[n];
	for(i=0;i<n;i++)
	{
		temp[i]=proc[i].bt;
	}
	int r=n;
	int flag=0,sum=0;
	int avgwt=0,avgtt=0;
	i=0;
	while(r!=0)
	{
		if(temp[i]<=q && temp[i]!=0)
		{
			sum+=temp[i];
			flag=1;
			temp[i]=0;
		}
		else if(temp[i]>q)
		{
			temp[i]-=q;
			sum+=q;
		}
		if(flag==1 && temp[i]==0)
		{
			r--;
			proc[i].tt=sum-proc[i].at;
			proc[i].wt=proc[i].tt-proc[i].bt;
			avgtt+=proc[i].tt;
			avgwt+=proc[i].wt;
			proc[i].ct=sum;
			flag=0;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(proc[i+1].at<sum)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	printf("Pid\tAt\tBt\tWt\tTt\tCt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,proc[i].wt,proc[i]. tt,proc[i].ct);
	}
	printf("\nThe average waiting time =%0.2f\n",(float)avgwt/n);
	printf("\nThe average turnaround time =%0.2f\n",(float)avgtt/n);
}