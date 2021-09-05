#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long k,n;
        cin>>k>>n;

        long long res=1,sum=0,c=1,mod=1e9+7;

        while((c*k)<=n)
        {
            sum=1+(c*k);
            c++;
            res*=sum;

            res%=mod;
        }
        cout<<"Case "<<t<<": "<<res<<endl;
    }

    return 0;
}
/*
(1+k) (1+2k)
1+2k+k+2kk
1+3k+2kk (1+3k)
1+3k+3k+9kk+2kk+6kkk
1+6k+11kk+6kkk
*/
