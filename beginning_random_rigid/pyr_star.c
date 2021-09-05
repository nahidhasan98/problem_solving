#include<stdio.h>
int main()
{
    int n,i,j,k;
    printf("Maximum how many (odd number) stars do you want in a line?\t");
    scanf("%d",&n);

    if(n%2!=0)
    {
        for(i=1;i<=n/2+1;i++)
        {
            for(j=i;j<=n/2;j++)
            {
                printf(" ");
            }
            for(k=1;k<=i*2-1;k++)
            {
                printf("*");
            }
            printf("\n");
        }
        for(i=n/2;i>=1;i--)
        {
            for(j=i;j<=n/2;j++)
            {
                printf(" ");
            }
            for(k=1;k<=i*2-1;k++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nPlease enter an odd number.\n");
    }
    return 0;
}
