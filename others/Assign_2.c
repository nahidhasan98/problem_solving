#include<stdio.h>

int main()
{
    double sum=0,denom=1;

    for(int i=1;i<=150;i++)
    {
        if(i%2==0)
            sum-=1/denom;
        else if(i%2!=0)
            sum+=1/denom;

        denom+=2;
    }

    printf("Summation upto 150th terms: %lf\n",sum);

    return 0;
}
