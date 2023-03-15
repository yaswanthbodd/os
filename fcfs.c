
#include<stdio.h>
#include<conio.h>
void main()
{
    int arrival[10],burst[10],start[10],finish[10],wait[10],turn[10];
    int i,j,n,sum=0;
    float totalwait=0.0,totalturn=0.0;
    float avgwait=0.0,avgturn=0.0;
    start[0]=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter process %d Arrival and Burst time \n",(i+1));
        scanf("%d%d",&arrival[i],&burst[i]);
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<i;j++)
        {
            sum=sum+burst[j];
        }
        start[i]=sum;
    }
    for(i=0;i<n;i++)
    {
        finish[i]=burst[i]+start[i];
        wait[i]=start[i]-arrival[i];
        turn[i]=burst[i]+wait[i];
    }
    for(i=0;i<n;i++)
    {
        totalwait=totalwait+wait[i];
        totalturn=totalturn+turn[i];
    }
    avgwait=totalwait/n;
    avgturn=totalturn/n;
    printf("\n Arrival Burst Start Finish Wait Turn \n");
    for(i=0;i<n;i++)
    {
        printf("%7d %5d %5d %6d %4d %4d \n",arrival[i],burst[i],start[i],finish[i],wait[i],turn[i]);
    }
    printf("Average waiting time %f\n",avgwait);
    printf("Average turnaround time %f\n",avgturn);
    getch();
}
