#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int a,b,n;
        cin>>a>>b>>n;

        int res=a^b;

        if(n%3==0)
            cout<<a<<endl;
        else if(n%3==1)
            cout<<b<<endl;
        else if(n%3==2)
            cout<<res<<endl;
    }

    return 0;
}
