#include<bits/stdc++.h>
using namespace std;

struct st
{
    int type, i, x;
};

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n];

        for(int i=1; i<=n; i++)
            cin>>a[i];

        st result[n+2];
        int desire=a[n]-1,ind=0;

        for(int i=n-1; i>=1; i--)
        {
            if(a[i]<desire)
            {
                int x=desire-a[i];

                result[ind].type=1;
                result[ind].i=i;
                result[ind].x=x;
                ind++;

                for(int j=1;j<=i;j++)
                    a[j]+=x;

                desire=a[i]-1;
            }
            else if(a[i]>desire)
            {
                int x=a[i]-desire;

                result[ind].type=2;
                result[ind].i=i;
                result[ind].x=x;
                ind++;

                for(int j=1;j<=i;j++)
                    a[j]%=x;

                desire=a[i]-1;
            }
            else
                desire=a[i]-1;
        }
        cout<<ind<<endl;

        for(int i=0;i<ind;i++)
            cout<<result[i].type<<' '<<result[i].i<<' '<<result[i].x<<endl;
    }

    return 0;
}
