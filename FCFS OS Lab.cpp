#include <stdio.h>
#include <string.h>
#include <conio.h>
int main()
{
	char pn[10][10],t[10];
	int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,j,n,temp;
	int totwt=0,tottat=0;
	printf("Enter the no. of porcesses:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the process Name,Arrival Time and Burst Time:");
		scanf("%s %d %d",&pn[i],&arr[i],&bur[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				temp=bur[i];
				bur[i]=bur[j];
				bur[j]=temp;
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
			star[i]=arr[i];
		}
		else
		{
			star[i]=finish[i-1];
		}
		wt[i]=star[i]-arr[i];
		finish[i]=star[i]+bur[i];
		tat[i]=finish[i]-arr[i];
	}
	printf("\nName 	ArrTime 	BurTime 	WaitTime 	Start 	TAT 	Finish");
	for(i=0;i<n;i++)
	{
		printf("\n %s \t %3d \t %3d \t %3d \t %3d \t %6d \t %6d",pn[i],arr[i],bur[i],wt[i],star[i],tat[i],finish[i]);
	totwt+=wt[i];
	tottat+=tat[i];
}
	printf("\n\naverage waiting time: %f",(float)totwt/n);
	printf("\n\nAverage time around time:%f",(float)tottat/n);
	getch();
	return 0;
}
