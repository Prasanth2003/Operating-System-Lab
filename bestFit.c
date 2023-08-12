//Program to inplement best fit memory allocation
#include <stdio.h>
void main()
{
	printf("Best Fit memory allocation\n\n");
	int m,n;
	int i,j;
	printf("Enter the number of processes and number of blocks in order:");
	scanf("%d %d",&n,&m);
	int alloc[n];
	for(i=0;i<n;i++)
	{
		alloc[i]=-1;
	}
	int block[m];
	printf("Enter the blocks:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&block[i]);
	}
	int proc[n];
	printf("Enter the process sizes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&proc[i]);
	}
	//Best fit allocation
	for(i=0;i<n;i++)
	{
		int best=-1;
		for(j=0;j<m;j++)
		{
			if(block[j]>=proc[i])
			{
				if(best==-1)
				{
					best=j;
				}
				else if(block[j]<block[best])
				{
					best=j;
				}
			}
		}
		if(best!=-1)
		{
			alloc[i]=best;
			block[best]-=proc[i];
		}
	}
	printf("Block Sizes remaining:\n");
	for(j=0;j<m;j++)
	{
		printf("%d\t",block[j]);
	}
	printf("\n");
	printf("Process order:\n");
	for(i=0;i<n;i++)
	{
		printf("%d |\t",i+1);
	}
	printf("\n");
	printf("Process allocated order:\n");
	for(i=0;i<n;i++)
	{
		if(alloc[i]!=-1)
		{
			printf("%d |\t",alloc[i]+1);
		}
		else
		{
			printf("not allocated |\t");
		}
	}
	printf("\n");
}
