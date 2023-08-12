//Program to implement banker’s algorithm for deadlock avoidance
#include <stdio.h>
void main()
{
	int pn,rn;
	int i,j;
	printf("\nEnter the number of processes and resources:");
	scanf("%d %d",&pn,&rn);
	int alloc[pn][rn],max[pn][rn],need[pn][rn];
	int avail[rn];
	printf("\nEnter the alloctaion matrix:\n");
	for(i=0;i<pn;i++)
	{
		for(j=0;j<rn;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\nEnter the max matrix:\n");
	for(i=0;i<pn;i++)
	{
		for(j=0;j<rn;j++)
		{
	scanf("%d",&max[i][j]);
	}
	}
	printf("\nEnter the available resources:");
	for(i=0;i<rn;i++)
	{
	scanf("%d",&avail[i]);
	}
	for(i=0;i<pn;i++)
	{
	for(j=0;j<rn;j++)
	{
	need[i][j]=max[i][j]-alloc[i][j];
	}
	}
	int flag[pn],ans[pn];
	for(i=0;i<pn;i++)
	flag[i]=0;
	printf("\nThe need matrix is:\n");
	for(i=0;i<pn;i++)
	{
	for(j=0;j<rn;j++)
	{
	printf("%d\t",need[i][j]);
	}
	printf("\n");
	}
	int k=0,index=0,f;
	for(k;k<pn;k++)
	{
	for(i=0;i<pn;i++)
	{
	f=0;
	if(flag[i]==0)
	{
	for(j=0;j<rn;j++)
	{
	if(need[i][j]>avail[j])
	{
	f=1;
	break;
	}
	}
	if(f==0)
	{
	ans[index++]=i;
	flag[i]=1;
	for(j=0;j<rn;j++)
	avail[j]+=alloc[i][j];
	}
	}
	}
	}
	f=0;
	for(i=0;i<pn;i++)
	{
	if(flag[i]==0)
	{
	printf("Deadlocked\n");
	f=1;
	break;
	}
	}
	if(f==0)
	{
	printf("The safe sequence is:");
	for(i=0;i<pn;i++)
	{
	if(i==pn-1)
	printf("%d\n",ans[i]);
	else
	printf("%d->",ans[i]);
	}
	}
	}
		