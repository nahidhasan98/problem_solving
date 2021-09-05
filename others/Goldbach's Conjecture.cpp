#include<bits/stdc++.h>
using namespace std;

int a[1000010];

void sieve()
{
    for(int i=2; i<=1000000; i++)
        a[i]=1;

    for(int i=2; i<=1000000; i++)
    {
        if(a[i]==1)
        {
            for(int j=i*2; j<=1000000; j+=i)
                a[j]=0;
        }
    }
}

int main()
{
    sieve();

    int n;

    while(cin>>n)
    {
        if(n==0)
            break;

        int flag=0;

        for(int i=2; i<=1000000/2; i++)
        {
            if(a[i]==1 && a[n-i]==1)
            {
                cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"Goldbach's conjecture is wrong."<<endl;
    }

    return 0;
}
