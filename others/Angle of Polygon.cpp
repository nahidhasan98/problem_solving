#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        double n;
        cin>>n;

        double res=((n-2)*180)/n;

        cout<<fixed<<setprecision(6)<<res<<endl;
    }

    return 0;
}
