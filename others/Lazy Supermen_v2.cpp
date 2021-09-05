#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        long double h1,h2,d;
        cin>>h1>>h2>>d;

        //cout<<d*h1<<endl;

        long double dis1=(d*h1)/(h1+h2);
        //long double dis2=(d*h2)/(h1+h2);

        //cout<<dis1<<' '<<dis2<<endl;

        long double res1=(h1*h1)+(dis1*dis1);
        long double res2=(h2*h2)+((d-dis1)*(d-dis1));

        res1=sqrt(res1);
        res2=sqrt(res2);

        cout<<fixed<<setprecision(4)<<res1<<' '<<res2<<endl;
    }

    return 0;
}
/*
3
24 15 100
100 250 34510
20 20 20

66.0529 41.2830
9860.5071 24651.2677
22.3607 22.3607

1
100000 1 100000
*/
