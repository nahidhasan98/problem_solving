#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        double a;
        cin>>a;

        cout<<fixed<<setprecision(6)<<(3*sqrt(3)*a*a)/2<<endl;
    }

    return 0;
}
