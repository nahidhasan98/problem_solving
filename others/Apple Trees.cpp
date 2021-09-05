#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;

    while(cin>>n)
    {
        long long res=0,i,mod=1000000007;
        long long ten=0,twenty=0,thirty=0,fourty=0,old,sum=0,temp,newT;

        for(i=0;i<=n;i+=10)
        {
            if(i==0) sum=1;
            else sum=((ten*16)%mod)+((twenty*9)%mod)+((thirty*4)%mod)+((fourty*1)%mod);
            newT=sum;
            res=(sum+ten+twenty+thirty+fourty)%mod;

            old=fourty;
            fourty=thirty;
            thirty=twenty;
            twenty=ten;
            ten=newT;
            cout<<"i= "<<i<<' '<<res<<endl;
        }
        i-=10;
        if(n-i>=5)
            res-=old;

        cout<<res<<endl;
    }

    return 0;
}
