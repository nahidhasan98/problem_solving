#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int d=1;

        for(int i=1;i<=n;i++)
        {
            cout<<d<<' '<<d+1<<' '<<d+2<<" PUM"<<endl;
            d+=4;
        }
    }

    return 0;
}
