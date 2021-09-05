#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    double h,m;

    while(cin>>h>>m)
    {
        h=h*5;

        h+=(m*5)/60;

        double diff=abs(h-m);

        if(diff>30)
            diff=60-diff;

        cout<<fixed<<setprecision(6)<<diff*6<<endl;
    }

    return 0;
}
