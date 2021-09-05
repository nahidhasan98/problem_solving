#include<iostream>
#include<cstring>
using namespace std;

int prime[10000005];

void sieve()
{
    for(int i=2; i<=1e7; i++)
    {
        if(prime[i]==0)
        {
            for(int j=2; i*j<=1e7; j++)
                prime[i*j]=1;
        }
    }
}
long long power(long long base,long long exp)
{
    long long sum=1;

    for(int i=1;i<=exp;i++)
        sum*=base;

    return sum;
}
int main()
{
    long long n,k;

    while(cin>>n>>k)
    {
        if(n==0 && k==0)
            break;

        sieve();

        int counterN[n+1],counterK[k+1],counterN_K[n-k+1];
        memset(counterN,0,sizeof(counterN));
        memset(counterK,0,sizeof(counterK));
        memset(counterN_K,0,sizeof(counterN_K));

        for(int i=2; i<=n; i++)
        {
            if(prime[i]==0)
            {
                int base=i,exp=1;

                while(base<=n)
                {
                    counterN[i]+=n/base;

                    if(i<=k) counterK[i]+=k/base;
                    if(i<=n-k) counterN_K[i]+=(n-k)/base;

                    exp++;
                    base=power(i,exp);
                }
            }
        }
//        for(int i=2;i<=n;i++)
//            if(counterN[i]!=0) cout<<counterN[i]<<' ';
//        cout<<endl;
//        for(int i=2;i<=k;i++)
//            if(counterK[i]!=0) cout<<counterK[i]<<' ';
//        cout<<endl;
//        for(int i=2;i<=n-k;i++)
//            if(counterN_K[i]!=0) cout<<counterN_K[i]<<' ';
//        cout<<endl;

        for(int i=2;i<=k;i++)
            counterN[i]-=counterK[i];

//        for(int i=2;i<=n;i++)
//            if(counterN[i]!=0) cout<<counterN[i]<<' ';
//        cout<<endl;
//
        for(int i=2;i<=n-k;i++)
            counterN[i]-=counterN_K[i];

//        for(int i=2;i<=n;i++)
//            if(counterN[i]!=0) cout<<counterN[i]<<' ';
//        cout<<endl;

        long long sum=1;

        for(int i=2;i<=n;i++)
        {
            if(counterN[i]!=0)
                sum*=power(i,counterN[i]);
        }
        cout<<sum<<endl;
    }

    return 0;
}
