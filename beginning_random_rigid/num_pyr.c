#include<stdio.h>
int main()
{
    int n,i,j,k,l;
    printf("Please enter an integer between 1-9:\t");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");
        for(k=i;k>=1;k--)
            printf("%d",k);
        for(l=2;l<=i;l++)
            printf("%d",l);
        printf("\n");
    }
    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=n-i;j++)
            printf(" ");
        for(k=i;k>=1;k--)
            printf("%d",k);
        for(l=2;l<=i;l++)
            printf("%d",l);
        printf("\n");
    }
}
