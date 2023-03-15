#include<stdio.h>
#include<conio.h>
void main()
{
    int memory[25];
    int i,len,startaddr,flag,endaddr,name;
    for(i=0;i<25;i++)
    {
        memory[i]=0;
        printf("%d ",memory[i]);
    }
    printf("\n Enter file name(0 to quit): ");
    scanf("%d",&name);
    while(name!=0)
    {
        printf("\n Enter length of file: ");
        scanf("%d",&len);
        printf("\n Enter starting location of the file: ");
        scanf("%d",&startaddr);
        endaddr=startaddr+len;
        flag=0;
        for(i=startaddr;(i<endaddr && endaddr<25);i++)
        {
            if(memory[i]!=0)
            {
                flag=1;
                printf("\n No sufficient memory to fill...");
                break;
            }
        }
        if(flag==0)
        {
            for(i=startaddr;i<endaddr;i++)
            {
                memory[i]=name;
            }
        }
        printf("\n Enter file name (0 to quit): ");
        scanf("%d",&name);
    }
    for(i=0;i<25;i++)
    {
        printf("%d",memory[i]);
    }
}
