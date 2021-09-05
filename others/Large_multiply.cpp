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

    reverse(ns.begin(),ns.end());

    return ns;
}
string multi(string p,string q)
{
    string forsum[500],op="";
    int ind=0,kk=0;
    for(int ii=q.size()-1;ii>=0;ii--)
    {
        string mstr="",mtt="";
        mtt[0]='0';
        for(int jj=p.size()-1;jj>=0;jj--)
        {
            int mcarry=mtt[0]-'0';
            int mq=q[ii]-'0';
            int mp=p[jj]-'0';

            int madd=mcarry+(mp*mq);

            if(madd>9)
            {
                int mc=(madd%10);
                string mc1="";
                mc1=mc+'0';

                mstr=mstr+mc1;
                int mcc=madd/10;
                mtt[0]=mcc+'0';
            }
            else
            {
                string mc2 = "" ;
                mc2+=madd+'0';
                mstr=mstr+mc2;
                mtt[0]='0';
            }
        }
        if(mtt[0]!='0')
            mstr=mstr+mtt[0];

        reverse(mstr.begin(),mstr.end());

        forsum[ind]=mstr+op;
        ind++;
        op=op+'0';
    }

    for(kk=0;kk<ind-1;kk++)
    {
        string tmp_forsum=sum(forsum[kk],forsum[kk+1]);
        forsum[kk+1]=tmp_forsum;
    }
    string fmulti="";
    fmulti=forsum[kk];

    return fmulti;
}
int main()
{
    string a,b;

    while(cin>>a>>b)
    {
        string ss=multi(a,b);

        cout<<ss<<endl;
    }

    return 0;
}
