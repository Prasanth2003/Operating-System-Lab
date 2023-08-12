//Program to implement FIFO and LRU page replacement algorithm
#include <stdio.h>
void fifo(int ref[],int frame[],int n,int m)
{
	int j=0,i,flag,count=0,k;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(k=0;k<m;k++)
		{
			if(frame[k]==ref[i])
			{
				flag=1;
				printf("Hit\n");
			}
		}
		if (flag==0)
		{
			frame[j]=ref[i];
			j=(j+1)%m;
			count++;
			for(k=0;k<m;k++)
			{
				if(frame[k]==-1)
				printf("-\t");
				else
				printf("%d\t",frame[k]);
			}
		}
		printf("\n");
	}
	printf("Number of page faults=%d",count);
}
void lru(int ref[],int frame[],int n,int m)
{
	int flag1,flag2,i,j,countarr[20],count=0,f=0;
	for (i=0;i<n;i++)
	{
		flag1=flag2=0;
		for (j=0;j<m;j++)
		{
			if (frame[j]==ref[i])
			{
				count++;
				countarr[j]=count;
				flag1=flag2=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<m;j++)
			{
				if (frame[j]==-1)
				{
					count++;
					f++;
					frame[j]=ref[i];
					countarr[j]=count;
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			int k,min=countarr[0],pos=0;
			for(k=1;k<m;k++)
			{
				if(countarr[k]<min)
				{
					min=countarr[k];
					pos=k;
				}
			}
			count++;
			f++;
			frame[pos]=ref[i];
			countarr[pos]=count;
		}
		printf("\n");
		for(j=0;j<m;j++)
		{
			if(frame[j]==-1)
			printf("-\t");
			else
			printf("%d\t",frame[j]);
		}
		printf("\n");
	}
	printf("\nThe number of page faults=%d",f);
}
void main()
{
	int ans=1;
	while(ans)
	{
		int n,m,ref[50],frame[10];
		printf("\nEnter the number of pages:");
		scanf("%d",&n);
		printf("\nEnter the reference string:");
		for(int i=0;i<n;i++)
		scanf("%d",&ref[i]);
		printf("\nEnter the number of frames:");
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		frame[i]=-1;
		printf("1-FIFO\n2-LRU\n");
		int ch;
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\n");
				fifo(ref,frame,n,m);
				break;
			}
			case 2:
			{
				printf("\n");
				lru(ref,frame,n,m);
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