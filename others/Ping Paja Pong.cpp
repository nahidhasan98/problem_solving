#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        long long x,y,k;
        cin>>x>>y>>k;

        long long total=x+y;

        if((total/k)%2==0)
            cout<<"Chef"<<endl;
        else if((total/k)&2!=0)
            cout<<"Paja"<<endl;
    }

    return 0;
}
