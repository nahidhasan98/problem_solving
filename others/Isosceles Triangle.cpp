#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        if((a==b && a!=c) || (b==c && b!=a) || (c==a && c!=b))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
