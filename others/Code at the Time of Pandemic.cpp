#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long New[33],Total[33];

void calculate()
{
    New[1]=0,Total[1]=1;

    for(int i=2;i<=30;i++)
    {
        New[i]=Total[i-1]*2;
        Total[i]=Total[i-1]+New[i];
    }
}

int main()
{
    calculate();

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        cout<<"Case "<<t<<":"<<endl;
        for(int i=1;i<=n;i++)
            cout<<"Day = "<<i<<", New = "<<New[i]<<", Total = "<<Total[i]<<endl;
    }

    return 0;
}
