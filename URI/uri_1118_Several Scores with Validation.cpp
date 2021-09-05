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
            cout<<"novo calculo (1-sim 2-nao)"<<endl;

            double x;

            while(cin>>x)
            {
                if(x==2)
                    return 0;
                else if(x==1)
                {
                    break;
                }
                else
                {
                    cout<<"novo calculo (1-sim 2-nao)"<<endl;
                }
            }
            count=0,sum=0;
        }
    }

    return 0;
}

