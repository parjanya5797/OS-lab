//Priority Scheduling 
#include<stdio.h>
#include<conio.h>
int main()
{
	int et[30],ts,n,i,x=0,tot=0;
	char pn[10][10];
	printf("Enter the no of processes");
	scanf("%d",&n);
	printf("Enter the time Quantum");
	scanf("%d",&ts);
	for(i=0;i<n;i++)
	{
		printf("Enter the process name and the estimated time :");
		scanf("%s %d",pn[i],&et[i]);
	}
	printf("The process are :");
	for(i=0;i<n;i++)
	{
		printf("Process %d %s \n",i+1,pn[i]);
	}
	for(i=0;i<n;i++)
	{
		tot=tot+et[i];
	}
	while(x!=tot)
	{
		for(i=0;i<n;i++)
		{
			if(et[i]>ts)
			{
				x=x+ts;
				printf("\n %s -> %d",pn[i],ts);
				et[i]=et[i]-ts;			
			}
			else if((et[i]<=ts)&&(et[i]!=0))
			{
				x=x+et[i];
				printf("\n %s -> %d",pn[i],et[i]);
				et[i]=0;
			}
		}
	}
	printf("\n THe total estimated time is %d:",x);
	getch();
	
}
