#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d;

    while(cin>>a>>b>>c>>d)
    {
        long long res=0;

        res=max(res,a*b);
        res=max(res,a*c);
        res=max(res,a*d);

        res=max(res,b*c);
        res=max(res,b*d);

        res=max(res,c*d);

        cout<<res<<endl;
    }

    return 0;
}
