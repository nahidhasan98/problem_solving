#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,count=0,sum=0;

    while(cin>>a)
    {
        if(a<0 || a>10)
            cout<<"nota invalida"<<endl;
        else
        {
            sum=sum+a;
            count++;
        }

        if(count==2)
        {
            cout<<"media = "<<fixed<<setprecision(2)<<sum/2<<endl;
            break;
        }
    }

    return 0;
}
