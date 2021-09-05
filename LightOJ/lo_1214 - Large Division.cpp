#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        string s;
        long long b,x=0;

        cin>>s>>b;

        if(s[0]=='-')
            s=s.substr(1);
        if(b<0)
            b=b*(-1);

        for(int k=0;k<s.size();k++)
        {
            if(x>=b)
            {
                x=x%b;
            }
            x=(x*10)+(s[k]-'0');
        }
        x=x%b;

        if(x==0)
            cout<<"Case "<<i<<": divisible"<<endl;
        else
            cout<<"Case "<<i<<": not divisible"<<endl;
    }

    return 0;
}
