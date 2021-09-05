#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,t,c,m=1000000007,res;
    long int N;

    cin>>T;

    for(t=1;t<=T;t++)
    {
        cin>>N;

        res=(N*(N+1)*(N+2))/3;

        if(N%3==0)
        {
            c=N/3;
            res=((((c%m)*(N+1))%m)*(N+2))%m;
        }

        else if((N+1)%3==0)
        {
            c=(N+1)/3;
            res=((((N%m)*c)%m)*(N+2))%m;
        }
        else
        {
            c=(N+2)/3;
            res=((((N%m)*(N+1))%m)*c)%m;
        }


        cout<<"Case "<<t<<": "<<res<<endl;
    }

    return 0;
}
