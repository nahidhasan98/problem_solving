#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n][n],mx=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];

                if(i==0)
                    mx=max(mx,a[i][j]);
            }
        }

        int res=0;
        for(int i=sqrt(mx); i>=1; i--)
        {
            int flag=0;

            for(int j=1; j<n; j++)
            {
                if(a[0][j]%i==0)
                    continue;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                res=i;
                break;
            }
        }
//
//        int res=a[0][1];
//
//        for(int i=1;i<n;i++)
//        {
//            res=__gcd(res,a[0][i]);
//        }

        cout<<res<<' ';
        for(int i=1; i<n; i++)
        {
            cout<<a[0][i]/res;

            if(i<n-1)
                cout<<' ';
        }
        cout<<endl;
    }

    return 0;
}
