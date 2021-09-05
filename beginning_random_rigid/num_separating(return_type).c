#include<stdio.h>
int num,i=1,temp,a[99],temploop,j,b[99];
int separate(int num);
int main()
{
    int n;
    printf("Please enter a number:\t");
    scanf("%d",&n);

    separate(n);

    printf("\nYour entered number after separating:\n");
    for(j=1;j<=temploop;j++)
        printf("b[%d]=%d\n",j,b[j]);
}
int separate(int num)
{
    temp=num;
    while(temp!=0)
    {
        a[i]=temp%10;
        temp=temp/10;
        i++;
    }
    i=i-1;
    temploop=i;

    for(j=1;j<=temploop;j++)
    {
        b[j]=a[i];
        i--;
    }

    return b;
}
