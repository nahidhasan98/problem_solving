#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    //FI FO

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        string s;
        int d,zero=0;

        cin>>s>>d;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                zero=1;
                break;
            }
        }

        int res=1,sz=s.size();

        if(zero==1)
        {
            sz--;
            res*=sz;

            for(int i=2;i<=d;i++)
            {
                res*=sz;
                sz--;
            }
        }
        else
        {
            for(int i=1;i<=d;i++)
            {
                res*=sz;
                sz--;
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
/*
10
9087654321 1
9087654321 2
9087654321 3
9087654321 4
9087654321 5
9087654321 6
9087654321 7
9087654321 8
9087654321 9
9087654321 10
*/
