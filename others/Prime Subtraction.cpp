#include<bits/stdc++.h>
using namespace std;

int a[100001];
vector<int>v;

void sieve()
{
    for(int i=2;i<=100000;i++)
        a[i]=1;

    for(int i=2;i<=100000;i++)
    {
        if(a[i]==1)
        {
            for(int j=2;i*j<=100000;j++)
                a[i*j]=0;
        }
    }

    for(int i=2;i<=100000;i++)
    {
        if(a[i]==1)
            v.push_back(i);
    }
}

int main()
{
    sieve();

//    for(int i=0;i<=100;i++)
//        cout<<v[i]<<endl;

//    cout<<v.size()<<endl;

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long x,y,r;
        cin>>x>>y;

        x-=y;
        int flag=0;

        for(int i=0;i<v.size();i++)
        {
            if(x%v[i]==0)
            {
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"NO"<<endl;
    }

    return 0;
}
