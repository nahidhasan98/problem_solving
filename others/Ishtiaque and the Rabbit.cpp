#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long mod=1000003;

long long exp(long long r,long long n)
{
    if(n==0) return 1;
    if(n==1) return r;

    if(n%2==0)
    {
        long long temp=exp(r,n/2)%mod;

        temp=(temp*temp)%mod;

        return temp;
    }
    else
    {
        n--;

        long long temp=exp(r,n/2)%mod;

        temp=(temp*temp)%mod;

        return (temp*(r%mod))%mod;
    }
}

long long calculate(long long r,long long n)
{
    long long up,down,res,temp;

    temp=exp(r,n);
    r=r%mod;

    if(temp<r)
        temp+=mod;

    cout<<"exp="<<exp(r,n)<<endl;
    up=(temp-r)%mod;
    down=r-1;

    if(up<down)
        up+=mod;

    cout<<"  up="<<up<<endl;
    cout<<"down="<<down<<endl;

    //res=((up%mod)/(down%mod))%mod;
    res=(up/down)%mod;

    cout<<"res="<<res<<endl;
    return res;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long a,r,n,res;
        cin>>a>>r>>n;

        if(n==1) res=a;
        else if(r==1) res=((a%mod)*(n%mod))%mod;
        else res=((a%mod)*(1+calculate(r,n))%mod)%mod;

        cout<<res<<endl;
    }

    return 0;
}
