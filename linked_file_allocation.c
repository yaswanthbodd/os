#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int bno,flag,bn[20];
}
block;
block b[100],b1;
void main()
{
    int rnum();
    int p[30],kk[20],i,n,t,s1,s,r,j,c=1;
    printf("\n Enter no of input files: ");
    scanf("%d",&n);
    printf("\n Input the requirements: ");
    for(i=1;i<=n;i++)
    {
        printf("\n Enter no of blocks needed for file %d: ",i);
        scanf("%d",&p[i]);
    }
    t=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=p[i];j++)
        {
            s=rnum();
            b[s].flag=1;
            b[c].bno=s;
            r=p[i]-1;
            kk[i]=s;
            t=1;
            c++;
        }
    }
    while(r!=0)
    {
        s1=rnum();
        b[s].bn[t]=s1;
        b[s].flag=1;
        b[i].bno=s1;
        r=r-1;
        t=t+1;
    }
    c++;
    printf("\n allocation\n");
    c=1;
    for(i=1;i<=n;i++)
    {
        printf("\n allocated for file %d: ",i);
        for(j=1;j<=p[i];j++)
        {
            if(j==1)
            {
                printf("%3d",b[c].bno);
                c++;
            }
            else
            {
                printf("---> %3d",b[c].bno);
                c++;
            }
        }
        printf("\n");
    }
}
int rnum()
{
    int k=0,i;
    for(i=1;i<=100;i++)
    {
        k=rand()%100;
        k+=10;
        if(b[k].flag!=1)
            break;
    }
    return k;
}
