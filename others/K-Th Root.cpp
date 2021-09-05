#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long p[1000005];

void calculate()
{
    for(int i=2;i<=sqrt(1000000);i++)
    {
        long long res=1,ex=1;

        while(res<1000005)
        {
            res=res*i;

            if(res<1000005 && p[res]==0)
                p[res]=ex;

            ex++;
        }
    }
//    for(int i=1;i<=1000000;i++)
//        cout<<b[i]<<' '<<p[i]<<endl;
}

int main()
{
    calculate();

    int q;
    cin>>q;

    for(int t=1;t<=q;t++)
    {
        long long a,b;
        cin>>a>>b;

        if(p[a]==0)
            cout<<"Case #"<<t<<": "<<b<<endl;
        else
            cout<<"Case #"<<t<<": "<<p[a]*b<<endl;
    }

    return 0;
}
