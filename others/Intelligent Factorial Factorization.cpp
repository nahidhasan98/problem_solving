#include<bits/stdc++.h>
using namespace std;

int prime[105];

void sieve()
{
    for(int i=2; i<=1e2; i++)
    {
        if(prime[i]==0)
        {
            for(int j=2; i*j<=1e2; j++)
                prime[i*j]=1;
        }
    }
}
long long power(long long base,long long exp)
{
    long long sum=1;

    for(int i=1; i<=exp; i++)
        sum*=base;

    return sum;
}
int main()
{
    sieve();

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n;
        cin>>n;

        int counter[n+1],factor=0,prnt=0;
        memset(counter,0,sizeof(counter));

        for(int i=2; i<=n; i++)
        {
            if(prime[i]==0)
            {
                factor++;
                int base=i,exp=1;

                while(base<=n)
                {
                    counter[i]+=n/base;

                    exp++;
                    base=power(i,exp);
                }
            }
        }
        cout<<"Case "<<t<<": "<<n<<" = ";
        for(int i=2; i<=n; i++)
        {
            if(counter[i]!=0)
            {
                cout<<i<<" ("<<counter[i]<<")";

                prnt++;

                if(prnt<factor)
                    cout<<" * ";
            }
        }
        cout<<endl;

    }

    return 0;
}
