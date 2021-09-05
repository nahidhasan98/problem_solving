#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n,d;
        cin>>n;

        int pos[110]={0},neg[110]={0};

        for(int i=1;i<=n;i++)
        {
            cin>>d;

            if(d>=0)
                pos[d]++;
            else
                neg[abs(d)]++;
        }
        int res=-1,value=neg[1];

        for(int i=2;i<100;i++)
        {
            if(neg[i]>value)
            {
                res=-i;
                value=neg[i];
            }
        }
        //cout<<neg[1]<<' '<<neg[2]<<' '<<res<<endl;
        for(int i=0;i<100;i++)
        {
            if(pos[i]>value)
            {
                res=i;
                value=pos[i];
            }
        }

        cout<<res<<endl;
    }

    return 0;
}
