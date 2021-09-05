#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int fact(int n)
{
    if(n==0 || n==1)
        return 1;

    return n*fact(n-1);
}

int npr(int n,int r)
{
    if(r==0)
        return 1;

    return fact(n)/fact(n-r);
}

int main()
{
    FI FO

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        string s;
        int d,flag=0;

        cin>>s>>d;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<npr(s.size(),d)<<endl;
        else
            cout<<(npr(s.size(),d)*(s.size()-1))/s.size()<<endl;
    }

    return 0;
}
