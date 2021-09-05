#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x,y;

    while(cin>>x>>y)
    {
        long long sum=0;

        for(int i=min(x,y);i<=max(x,y);i++)
        {
            if(i%13!=0)
                sum+=i;
        }
        cout<<sum<<endl;
    }

    return 0;
}
