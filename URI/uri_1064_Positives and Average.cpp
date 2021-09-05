#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a[6],sum=0;
    int count=0;

    for(int i=0;i<6;i++)
    {
        cin>>a[i];

        if(a[i]>0)
        {
            count++;

            sum=sum+a[i];
        }
    }

    cout<<count<<" valores positivos"<<endl;
    cout<<fixed<<setprecision(1)<<sum/count<<endl;

    return 0;
}

