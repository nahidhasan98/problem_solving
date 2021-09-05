#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float c=0,r=0,s=0,d;
    char ss;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>d>>ss;

        if(ss=='C')
            c=c+d;
        else if(ss=='R')
            r=r+d;
        else
            s=s+d;
    }
    cout<<"Total: "<<(c+r+s)<<" cobaias"<<endl;
    cout<<"Total de coelhos: "<<c<<""<<endl;
    cout<<"Total de ratos: "<<r<<""<<endl;
    cout<<"Total de sapos: "<<s<<""<<endl;

    cout<<"Percentual de coelhos: "<<fixed<<setprecision(2)<<(c*100)/(c+r+s)<<" %"<<endl;
    cout<<"Percentual de ratos: "<<fixed<<setprecision(2)<<(r*100)/(c+r+s)<<" %"<<endl;
    cout<<"Percentual de sapos: "<<fixed<<setprecision(2)<<(s*100)/(c+r+s)<<" %"<<endl;

    return 0;
}


