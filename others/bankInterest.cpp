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
        long double p,y;
        long double r1,r2;

        cin>>p>>y>>r1>>r2;
        r1=r1/100;
        r2=r2/100;

        long double comp=p*pow((1+r1),y);
        long double simple=p*(1+(r2*y));

        long double compI=comp-p;
        long double simpI=simple-p;

//        cout<<comp<<' '<<compI<<endl;
//        cout<<simple<<' '<<simpI<<endl;

        if(compI<simpI)
            cout<<"Bank 1"<<endl;
        else if( simpI<compI)
            cout<<"Bank 2"<<endl;
        else if (simpI==compI)
            cout<<"Confused huh!"<<endl;
    }

    return 0;
}
