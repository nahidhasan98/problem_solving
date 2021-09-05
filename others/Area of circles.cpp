#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    double x,y,r,sum=0,pi=acos(-1);

    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>r;

        sum+=pi*r*r;
    }
    cout<<sum<<endl;

    return 0;
}
