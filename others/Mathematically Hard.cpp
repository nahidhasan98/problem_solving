#include<bits/stdc++.h>
using namespace std;

//int prime[5000010];
long long scoreTable[5000010];

//void sieve()
//{
//    for(int i=2; i<=50000; i++)
//        prime[i]=1;
//
//    for(int i=2; i<=10000; i++)
//    {
//        if(prime[i])
//        {
//            for(int j=i*i; j<=10000; j+=i)
//                prime[j]=0;
//        }
//    }
//}
long long power(int base,int exp)
{
    long long sum=1;

    for(int i=1; i<=exp; i++)
        sum*=base;

    return sum;
}
long long phi(int n)
{

    //finding prime factorization
    int z=2,counter=0;
    long long sum=1;

    while(z*z<=n)
    {
        if(n%z==0)
        {
            counter++;
            n/=z;
        }
        else
        {
            int base=z;
            int exp=counter;

            sum*=power(base,exp)-power(base,exp-1);

            counter=0;
            z++;
        }
    }
    sum*=power(n,1)-power(n,1-1);

    return sum;
}
void score()
{
    for(int i=2; i<=5000000; i++)
    {
        cout<<i<<' ';
        long long temp=phi(i);
        scoreTable[i]=temp*temp;
    }
}
int main()
{
    //sieve();
    score();

    cout<<"Hello"<<endl;
    for(int i=2; i<=50000; i++)
    {
        cout<<scoreTable[i]<<' ';
    }

//    int test;
//    cin>>test;
//
//    for(int t=1; t<=test; t++)
//    {
//        long long a,b;
//        cin>>a>>b;
//
//        int phiA,phiB;
//
//        if(prime[a])
//            phiA=a-1;
//        else
//            phiA=phi(a);
//
//        if(prime[b])
//            phiB=b-1;
//        else
//            phiB=phi(b);
//
//
//
//
//        cout<<"Case "<<t<<": "<<<<endl;
//    }

    return 0;
}
