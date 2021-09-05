#include<bits/stdc++.h>
using namespace std;

int main()
{
    float n;

    while(cin>>n)
    {
        if(n<=2000)
            cout<<"Isento"<<endl;

        else if(n>2000 && n<=3000)
            cout<<"R$ "<<fixed<<setprecision(2)<<(((n-2000)*8)/100)<<endl;
        else if(n>3000 && n<=4500)
            cout<<"R$ "<<fixed<<setprecision(2)<<((1000*8)/100)+(((n-3000)*18)/100)<<endl;
        else if(n>4500)
            cout<<"R$ "<<fixed<<setprecision(2)<<((1000*8)/100)+((1500*18)/100)+(((n-4500)*28)/100)<<endl;
    }

    return 0;
}

