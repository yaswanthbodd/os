#include<stdio.h>
#include<conio.h>
void main()
{
    int burst[10],pri[10],wait[10],start[10],finish[10];
    int i,j,temp1,temp2,n,totalwait=0,totalavg=0,totalturn=0;
    float avgwait=0.0,avgturn=0.0;
    printf("Enter n value ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter Burst time and priority of process %d \n",i);
        scanf("%d %d",&burst[i],&pri[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(pri[i]>pri[j])
            {
                temp1=pri[i];
                pri[i]=pri[j];
                pri[j]=temp1;
                temp2=burst[i];
                burst[i]=burst[j];
                burst[j]=temp2;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            start[i]=0;
            finish[i]=burst[i];
            wait[i]=start[i];
        }
        else
        {
            start[i]=finish[i-1];
            finish[i]=start[i]+burst[i];
            wait[i]=start[i];
        }
    }
    printf("\n Burst Priority Start Wait Finish \n");
    for(i=1;i<=n;i++)
    {
        printf("%5d %8d %5d %4d %6d \n",burst[i],pri[i],start[i],wait[i],finish[i]);
    }
    for(i=1;i<=n;i++)
    {
        totalwait=totalwait+wait[i];
        totalturn=totalturn+finish[i];
    }
    avgwait=totalwait/n;
    avgturn=totalturn/n;
    printf("\n Average waiting time=%f\n",avgwait);
    printf("\n Average turnaround time=%f\n",avgturn);
}
