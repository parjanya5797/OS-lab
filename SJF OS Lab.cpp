#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
	int et[10],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10];
	float awt,ata;
	int totwt=0,tottat=0;
	char pn[10][10],t[10];
	printf("Enter the no of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the process name,arrival time and execution time:");
		scanf("%s %d %d",&pn[i],&at[i],&et[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(et[i]<et[j])
			{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=et[i];
				et[i]=et[j];
				et[j]=temp;
				strcpy(t,pn[i]);
				strcpy(pn[i],pn[j]);
				strcpy(pn[j],t);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			st[i]=at[i];
		}
		else
		{
			t[i]=ft[i-1];
		}
		wt[i]=st[i]-at[i];
		ft[i]=st[i]+et[i];
		ta[i]=ft[i]-at[i];
		totwt+=wt[i];
		tottat+=ta[i];
	}
	awt=(float)totwt/n;
	ata=(float)tottat/n;
	printf("\nPname\tarrival time\texecution time\t waiting time\ttatime");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],et[i],wt[i],ta[i]);
	}
	printf("\n\nAverage waiting time is:%f",awt);
	printf("\n\nAverage turnaround time is:%f",ata);
	getch();
}
