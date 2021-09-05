#include<stdio.h>
int main()
{
    int n,row,i;

    printf("Please enter the number of row:\t");
    scanf("%d",&n);

    for(row=1;row<=n;row++)
    {
        if(row%2!=0)
        {
            for(i=1;i<=n+1;i++)
                {
                    if(i%2!=0)
                        printf("    ");
                    else
                        printf("1111");
                }
            printf("\n");
        }
        else
        {
            for(i=1;i<=n+1;i++)
                {
                    if(i%2!=0)
                        printf("1111");
                    else
                        printf("    ");
                }
            printf("\n");
        }
    }

    return 0;
}
