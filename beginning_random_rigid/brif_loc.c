#include<stdio.h>
int num,i=1,u[99],c[99],temp,a[99],temploop,j,b[99],old,pat;
int separate(int num);
int main()
{
    int n,z,unlock,current;
    printf("How many test you want to do?\t");
    scanf("%d",&n);

    for(z=1;z<=n;z++)
    {
        if(z==1||z==11||z==21||z==31||z==41||z==51||z==61||z==71||z==81||z==91||z==101)
            printf("\nWelcome to %dst test.\nPlease enter the unlock code:\t",z);
        else if(z==2||z==12||z==22||z==32||z==42||z==52||z==62||z==72||z==82||z==92||z==102)
            printf("\nWelcome to %dnd test.\nPlease enter the unlock code:\t",z);
        else if(z==3||z==13||z==23||z==33||z==43||z==53||z==63||z==73||z==83||z==93||z==103)
            printf("\nWelcome to %drd test.\nPlease enter the unlock code:\t",z);
        else
            printf("\nWelcome to %dth test.\nPlease enter the unlock code:\t",z);
        scanf("%d",&unlock);

        separate(unlock);
        for(j=1;j<=temploop;j++)
        {
            u[j]=a[i];
            i--;
        }

        printf("\nNow enter your current code:\t");
        scanf("%d",&current);

        separate(current);
        for(j=1;j<=temploop;j++)
        {
            c[j]=a[i];
            i--;
        }

        printf("\nYour entered number after separating:\n");
        for(j=1;j<=temploop;j++)
            printf("u[%d]=%d\tc[%d]=%d\n",j,u[j],j,c[j]);
    }
}
int separate(int num)
{
    i=1;
    temp=num;
    while(temp!=0)
    {
        a[i]=temp%10;
        temp=temp/10;
        i++;
    }
    i=i-1;
    temploop=i;

    return a;
}
