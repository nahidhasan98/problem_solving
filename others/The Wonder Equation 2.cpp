#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    //FI FO
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        long long n,res;
        cin>>n;

        long long sq=sqrt(n);

        if((sq*sq)==n)
        {
            long long X=sq-2;
            long long Y=X+1;

            if(X%2==0)
            {
                X/=2;
                res=X*Y;
            }
            else
            {
                Y/=2;
                res=X*Y;
            }
            cout<<res<<endl;
        }
        else
            cout<<0<<endl;
    }

    return 0;
}
