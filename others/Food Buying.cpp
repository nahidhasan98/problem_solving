#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long n;
        cin>>n;

        long long counter=0,rest=0;

        while(n>=10)
        {
            rest=n%10;

            counter+=n-rest;

            n=n/10;

            n+=rest;
        }
        counter+=n;

        cout<<counter<<endl;
    }

    return 0;
}
