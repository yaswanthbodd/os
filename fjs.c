#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j,burst[10],start[10],finish[10],wait[10];
    int n,temp;
    float totalwait=0.0,totalturn=0.0;
    float avgwait,avgturn;
    printf("Enter number of process: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter process %d Burst time: ",i);
        scanf("%d",&burst[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(burst[i]>burst[j])
            {
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            start[i]=0;
            finish[i]=burst[i];
            wait[i]=0;
        }
        else
        {
            start[i]=finish[i-1];
            finish[i]=start[i]+burst[i];
            wait[i]=start[i];
        }
    }
    printf("\n Burst start finish wait \n");
    for(i=1;i<=n;i++)
    {
        printf("%5d %5d %6d %4d \n",burst[i],start[i],finish[i],wait[i]);
    }
    for(i=1;i<=n;i++)
    {
        totalwait=totalwait + wait[i];
        totalturn=totalturn + finish[i];
    }
    avgwait=totalwait/n;
    avgturn=totalturn/n;
    printf("Average waiting time %f\n",avgwait);
    printf("Average turn over time %f",avgturn);
}
