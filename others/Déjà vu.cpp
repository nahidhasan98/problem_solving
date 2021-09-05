#include<bits/stdc++.h>
using namespace std;

int a[1000010];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,r;

    while(cin>>n>>r)
    {
        memset(a,0,sizeof(a));

        int d,mx=0;

        for(int i=1; i<=n; i++)
        {
            cin>>d;
            a[d]=1;

            mx=max(mx,d);
        }

        int counter=0,range;

        while(mx>=1)
        {
            if(a[mx]==1)
            {
                counter++;
                range=mx-r;

                for(int i=mx-1; i>=range; i--)
                {
                    if(i>=1 && i-r>=1)
                    {
                        if(a[i]==1)
                            a[i-r]=1;
                    }
                }
                mx=range-1;
            }
            else
                mx--;
        }
        cout<<counter<<endl;
    }

    return 0;
}
