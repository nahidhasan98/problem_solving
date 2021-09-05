#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    //FI FO
    int n,test=1;

    while(cin>>n)
    {
        if(n==0)
            break;

        string in,out,temp;
        map<char,int>yes,no;
        int flag=0,mx=-1;

        for(int t=1; t<=n; t++)
        {
            cin>>in>>out;

            in=in.substr(1,in.size()-2);
            out=out.substr(1,out.size()-2);

            if(out.size()<=in.size())
            {
                temp=in.substr(0,out.size());

                if(out==temp)
                {
                    for(int i=0; i<out.size(); i++)
                    {
                        yes[out[i]]=1;
                        mx=max(mx,(int)out[i]);
                    }

                    if(in.size()>temp.size())
                        no[in[temp.size()]]=1;
                }
                else
                    flag=1;
            }
            else
                flag=1;
        }
//        cout<<"No= ";
//        for(char i='0'; i<='9'; i++)
//            if(no[i]==1)
//                cout<<i;
//        for(char i='A'; i<='Z'; i++)
//            if(no[i]==1)
//                cout<<i;
//        for(char i='a'; i<='z'; i++)
//            if(no[i]==1)
//                cout<<i;
//        cout<<endl;
//
//        cout<<"Yes= ";
//        for(char i='0'; i<='9'; i++)
//            if(yes[i]==1)
//                cout<<i;
//        for(char i='A'; i<='Z'; i++)
//            if(yes[i]==1)
//                cout<<i;
//        for(char i='a'; i<='z'; i++)
//            if(yes[i]==1)
//                cout<<i;
//        cout<<endl;

        string res="";

        if(mx==-1)
        {
            for(char i='0'; i<='9'; i++)
                if(no[i]==0)
                    res+=i;
            for(char i='A'; i<='Z'; i++)
                if(no[i]==0)
                    res+=i;
            for(char i='a'; i<='z'; i++)
                if(no[i]==0)
                    res+=i;
            if(res.size()==0)
                flag=1;
            else
                res=res[0];
        }
        else
        {
            mx=(char)mx;

            for(char i='0'; i<='9' && i<=mx; i++)
            {
                if(yes[i]==1 && no[i]==1)
                    flag=1;
                else if(yes[i]==1 && no[i]==0)
                    res+=i;
                else if(yes[i]==0 && no[i]==0)
                    res+=i;
            }
            for(char i='A'; i<='Z' && i<=mx; i++)
            {
                if(yes[i]==1 && no[i]==1)
                    flag=1;
                else if(yes[i]==1 && no[i]==0)
                    res+=i;
                else if(yes[i]==0 && no[i]==0)
                    res+=i;
            }
            for(char i='a'; i<='z' && i<=mx; i++)
            {
                if(yes[i]==1 && no[i]==1)
                    flag=1;
                else if(yes[i]==1 && no[i]==0)
                    res+=i;
                else if(yes[i]==0 && no[i]==0)
                    res+=i;
            }
        }

        if(flag==1 || res.size()==0)
            cout<<"Case "<<test<<": I_AM_UNDONE"<<endl;
        else
            cout<<"Case "<<test<<": ["<<res<<"]"<<endl;

        test++;
    }

    return 0;
}
