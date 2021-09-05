#include<iostream>
#include<vector>
#include<math.h>
#include<cmath>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);

    for(int t=1;t<=test;t++)
    {
        int x,y,d;
        scanf("%d%d",&x,&y);

        vector<int>vx,vy;

        for(int i=1;i<=sqrt(x);i++)
        {
            d=x/i;

            if(i==d)
                vx.push_back(i);
            else
            {
                vx.push_back(i);
                vx.push_back(d);
            }
        }
        for(int i=1;i<=sqrt(y);i++)
        {
            d=y/i;

            if(i==d)
                vy.push_back(i);
            else
            {
                vy.push_back(i);
                vy.push_back(d);
            }
        }
        if(abs(vx.size()-vy.size())<=3)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
