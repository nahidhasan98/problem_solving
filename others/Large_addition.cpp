#include<bits/stdc++.h>
using namespace std;

string sum(string x,string y)
{
    int xx=x.size();
    int yy=y.size();
    int sz=max(xx,yy);

    if(xx>yy)
    {
        for(int i=0;i<(xx-yy);i++)
            y='0'+y;
    }
    else if(yy>xx)
    {
        for(int i=0;i<(yy-xx);i++)
            x='0'+x;
    }

    string ns="",tt="";
    tt[0]='0';
    for(int i=sz-1;i>=0;i--)
    {
        int a1,b1,carry;
        carry=tt[0]-'0';
        a1=(x[i]-'0');
        b1=(y[i]-'0');

        int add=carry+a1+b1;

        if(add>9)
        {
            int c=(add%10);
            string c1="";
            c1=c+'0';

            ns=ns+c1;
            int cc=add/10;
            tt[0]=cc+'0';
        }
        else
        {
            string c2 = "" ;
            c2+=add+'0';
            ns=ns+c2;
            tt[0]='0';
        }
    }
    if(tt[0]!='0')
        ns=ns+tt[0];

    return ns;
}
int main()
{
    string a,b;

    while(cin>>a>>b)
    {
        string ss=sum(a,b);

        reverse(ss.begin(),ss.end());
        cout<<ss<<"\n"<<endl;
    }

    return 0;
}
