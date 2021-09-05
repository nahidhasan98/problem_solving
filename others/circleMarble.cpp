#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        double p,q,z;
        cin>>p>>q>>z;

        double xc=p/2;
        double yc=q/2;

        double r2=(xc*xc)+(yc*yc)-z;
        double r=sqrt(r2);

        double n,xp,yp,counter=0;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>xp>>yp;

            double d=sqrt(((xp-xc)*(xp-xc))+((yp-yc)*(yp-yc)));

            if(d<=r) counter++;
        }
        cout<<counter<<endl;
    }

    return 0;
}
