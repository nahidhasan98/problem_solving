#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        double r1,r2,h,p,vol;

        cin>>r1>>r2>>h>>p;

        double pi=2*acos(0.0);

        double temp=((r1-r2)*(h-p))/h;

        double rm=r1-temp;

        vol=((pi*p)*((rm*rm)+(rm*r2)+(r2*r2)))/3;

        cout<<"Case "<<i<<": "<<fixed<<setprecision(8)<<vol<<endl;
    }

    return 0;
}
