#include<stdio.h>
int num,temp,a[10],temploop,j,b[10],x;
int separate(int num);
int main()
{
    int n,x=0,count=0,tmp;
    printf("Please enter a number:\t");
    scanf("%d",&n);

    tmp=n;

    for(n=n;n>=1;n--)
    {
        separate(n);

        for(x=1;x<=temploop;x++)
        {
            if(b[x]==2)
                count++;
        }
    }

    printf("\nThe number of 2's from 0 to %d is %d\n",tmp,count);

    return 0;
}
int separate(int num)
{
    int i=1;
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
