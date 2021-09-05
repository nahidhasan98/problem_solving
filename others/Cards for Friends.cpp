#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int w,h,n;
        cin>>w>>h>>n;

        int sum=1;

        while(w%2==0)
        {
            w/=2;
            sum*=2;

            if(sum>=n)
                break;
        }
        while(h%2==0)
        {
            h/=2;
            sum*=2;

            if(sum>=n)
                break;
        }
        if (sum>=n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
