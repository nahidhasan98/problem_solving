#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d,alcohol=0,gasoline=0,diesel=0;

    while(cin>>d)
    {
        if(d==1)
            alcohol++;
        else if(d==2)
            gasoline++;
        else if(d==3)
            diesel++;
        else if(d==4)
            break;
    }
    cout<<"MUITO OBRIGADO"<<endl;
    cout<<"Alcool: "<<alcohol<<endl;
    cout<<"Gasolina: "<<gasoline<<endl;
    cout<<"Diesel: "<<diesel<<endl;

    return 0;
}
