#include<bits/stdc++.h>
using namespace std;

struct st
{
    int mn,mx,diff,left;
};

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n,d;
        cin>>n>>d;

        long long a[n+1];

        for(int i=1;i<=n;i++)
            cin>>a[i];

        st b[n+1];
        st temp;

        temp.mn=0,temp.mx=0,temp.diff=0,temp.left=0;

        for(int i=1;i<=n;i++)
        {
            temp.mn=a[i];
            temp.mx=a[i];
            temp.left=i;
            temp.diff=a[i]-a[i];

            int range=i-temp.left+1;

            if(range>d)
            {
                if(a[temp.left]==temp.mn)

                    temp.left++;
            }
        }

        cout<<"Case "<<t<<": "<<<<endl;
    }

    return 0;
}
