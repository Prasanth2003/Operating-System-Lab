//Program to implement FCFS and SCAN disk scheduling algorithms
#include <stdio.h>
#include <stdlib.h>
void fcfs(int r[],int n,int initial)
{
	printf("%d->",initial);
	int T=0,i;
	for(i=0;i<n;i++)
	{
		T=T+abs(r[i]-initial);
		initial=r[i];
		if(i==n-1)
		printf("%d\n",r[i]);
		else
		printf("%d->",r[i]);
	}
	printf("Total head moment is=%d",T);
}
void scan(int r[],int n,int initial)
{
	int temp,max,hpos;
	int i,j;
	r[n]=initial;
	n=n+1;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(r[i]>r[j])
			{
				temp=r[i];
				r[i]=r[j];
				r[j]=temp;
			}
		}
	}
	max=r[n-1];
	for(i=0;i<n;i++)
	{
		if(initial==r[i])
		{
			hpos=i;
			break;
		}
	}
	for(i=hpos;i>=0;i--)
	{
		printf("%d->",r[i]);
	}
	printf("0->");
	for(i=hpos+1;i<n;i++)
	{
		if(i==n-1)
		printf("%d",r[i]);
		else
		printf("%d->",r[i]);
	}
	int sum=initial+max;
	printf("\nTotal head movement=%d",sum);
}
void main()
{
	int ans=1;
	while(ans)
	{
		int r[50],n,initial;
		printf("\n\nEnter the number of requests:");
		scanf("%d",&n);
		printf("Enter the requests sequence:");
		for(int i=0;i<n;i++)
		scanf("%d",&r[i]);
		printf("Enter initial head position:");
		scanf("%d",&initial);
		printf("\n1-FCFS\n2-SCAN\n");
		int ch;
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				fcfs(r,n,initial);
				break;
			}
			case 2:
			{
				scan(r,n,initial);
				break;
			}
			default:
			{
				printf("Wrong Choice\n");
				break;
			}
		}
		printf("\nEnter 1 to coninue:");
		scanf("%d",&ans);
	}
}
