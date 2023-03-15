#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct block
{
    int bno,flag;
};
struct block b[100];
int rnum();
void main()
{
    int p[10],r[10][10],ab[10],i,j,n,s;
    printf("\n Input");
    printf("\n Enter no.of files: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter size of block %d: ",i);
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++)
    {
        s=rnum();
        ab[i]=s;
        for(j=0;j<p[i];j++)
        {
            s=rnum();
            r[i][j]=s;
        }
    }
    printf("\n Output");
    for(i=1;i<=n;i++)
    {
        printf("\n file %d \n block %d contains: ",i,ab[i]);
        for(j=0;j<p[i];j++)
        {
            printf("%6d",r[i][j]);
        }
    }
}
int rnum()
{
    int k=0,i;
    for(i=1;i<=100;i++)
    {
        k=rand()%100;
        if(b[k].flag!=-1)
            break;
    }
    return k;
}
