#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        for(int i=2;i<=n;i+=2)
            cout<<i<<"^"<<2<<" = "<<i*i<<endl;
    }

    return 0;
}
