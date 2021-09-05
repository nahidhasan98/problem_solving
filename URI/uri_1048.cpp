#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a,p;

    while(cin>>a)
    {
        if((a>=0) && (a<=400))
            p=15;
        else if((a>=400.01) && (a<=800))
            p=12;
        else if((a>=800.01) && (a<=1200))
            p=10;
        else if((a>=1200.01) && (a<=2000))
            p=7;
        else if(a>2000)
            p=4;

        cout<<"Novo salario: "<<fixed<<setprecision(2)<<a+((a*p)/100)<<endl;
        cout<<"Reajuste ganho: "<<fixed<<setprecision(2)<<((a*p)/100)<<endl;
        cout<<"Em percentual: "<<fixed<<setprecision(0)<<p<<" %"<<endl;
    }

    return 0;
}
