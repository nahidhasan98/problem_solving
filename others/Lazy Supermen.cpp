#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        long long h1,h2,d,mul=100000;
        cin>>h1>>h2>>d;

        h1*=mul;
        h2*=mul;
        d*=mul;

        long long res1=0,res2=0,sum=0;

        long long low=0,high=d;
        long long mid=high;

        cout<<d<<' '<<mid<<' '<<d-mid<<endl;
        long long dis1=sqrt((h1*h1)+(mid*mid));
        long long dis2=sqrt((h2*h2)+((d-mid)*(d-mid)));

        cout<<dis1<<' '<<dis2<<endl;
        long long total=dis1+dis2;

        res1=dis1;
        res2=dis2;
        sum=total;
        cout<<"total "<<total<<" sum "<<sum<<endl;

        high=d;
        mid=(low+high)/2;

        while(low<high)
        {
            dis1=sqrt((h1*h1)+(mid*mid));
            dis2=sqrt((h2*h2)+((d-mid)*(d-mid)));
            total=dis1+dis2;

            if(total<=sum)
            {
                cout<<1<<endl;
                res1=dis1;
                res2=dis2;
                sum=total;

                high=mid-1;
                mid=(low+high)/2;
            }
            else
            {
                cout<<2<<endl;
                low=mid+1;
                mid=(low+high)/2;
            }
            cout<<"total= "<<total<<" sum= "<<sum<<endl;
        }

        cout<<fixed<<setprecision(5)<<res1<<' '<<res2<<endl;
    }

    return 0;
}
//34511.7748
//107.3359‬
//107.6632
/*
3
24 15 100
100 250 34510
20 20 20

66.0529 41.2830
9860.5071 24651.2677
22.3607 22.3607
*/
