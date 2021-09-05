#include<stdio.h>
#include<math.h>

int main()
{
    int test;
    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        int x,y,d;
        scanf("%d%d",&x,&y);

        int ax=0,ay=0;

        for(int i=1; i<=sqrt(x); i++)
        {
            if(x%i==0)
            {
                d=x/i;

                if(i==d)
                    ax++;
                else
                    ax+=2;
            }
        }
        for(int i=1; i<=sqrt(y); i++)
        {
            if(y%i==0)
            {
                d=y/i;

                if(i==d)
                    ay++;
                else
                    ay+=2;
            }
        }
        if(abs(ax-ay)<=3)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
