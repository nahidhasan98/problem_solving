#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

string one(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0')
            s[i]='1';
        else if(s[i]=='1')
            s[i]='0';
    }
    return s;
}

string two(string s)
{
    reverse(s.begin(),s.end());

    return s;
}

string three(string s)
{
    s=two(s);
    s=one(s);

    return s;
}

int main()
{
    int test,b;
    cin>>test>>b;

    if(b<=10)
    {
        for(int t=1; t<=test; t++)
        {
            string res="";
            char c,ans;

            for(int i=1; i<=b; i++)
            {
                cout<<i<<endl;
                cin>>ans;

                res+=ans;

                if(ans=='N')
                    return 0;
            }
            cout<<res<<endl;
            cin>>ans;

            if(ans=='N')
                return 0;
        }
    }
    else if(b>10)
    {
        for(int t=1; t<=test; t++)
        {
            string res1="",res2="",res3="",s="";
            char c,ans;

            for(int i=1; i<=5; i++)
            {
                cout<<i<<endl;
                cin>>ans;

                res1+=ans;

                if(ans=='N')
                    return 0;
            }
            for(int i=5; i<(b-5); i++)
            {
                res2+='X';
            }
            for(int i=(b-5); i<b; i++)
            {
                cout<<i+1<<endl;
                cin>>ans;

                res3+=ans;

                if(ans=='N')
                    return 0;
            }
            s+=res1;
            s+=res2;
            s+=res3;

            int change=0;

            cout<<1<<endl;
            cin>>ans;

            if(s[0]==ans)
            {
                if(ans==s[b-1])
                {
                    //24
                    for(int i=2; i<=5; i++)
                    {
                        if(s[i-1]!=s[b-i])
                        {
                            cout<<i<<endl;
                            cin>>ans;

                            if(s[i-1]==ans)
                                change=4;
                            else
                                change=2;
                            break;
                        }
                        else change=2;
                    }
                }
                else if(ans!=s[b-1])
                {
                    //34
                    for(int i=2; i<=5; i++)
                    {
                        if(s[i-1]==s[b-i])
                        {
                            cout<<i<<endl;
                            cin>>ans;

                            if(s[i-1]==ans)
                                change=4;
                            else
                                change=3;
                            break;
                        }
                    }
                }
            }
            else if(s[0]!=ans)
            {
                if(ans==s[b-1])
                {
                    //12
                    for(int i=2; i<=5; i++)
                    {
                        if(s[i-1]==s[b-i])
                        {
                            cout<<i<<endl;
                            cin>>ans;

                            if(s[i-1]==ans)
                                change=2;
                            else
                                change=1;
                            break;
                        }
                    }
                }
                else if(ans!=s[b-1])
                {
                    //13
                    for(int i=2; i<=5; i++)
                    {
                        if(s[i-1]!=s[b-i])
                        {
                            cout<<i<<endl;
                            cin>>ans;

                            if(s[i-1]==ans)
                                change=3;
                            else
                                change=1;
                            break;
                        }
                        change=1;
                    }
                }
            }

            if(change==1)
                s=one(s);
            else if(change==2)
                s=two(s);
            else if(change==3)
                s=three(s);
            else if(change==0)
            {
                if(ans=='0')
                {
                    s[0]='0';
                    s[1]='1';
                    s[2]='0';
                    s[3]='1';
                    s[4]='0';

                    s[b-1]='1';
                    s[b-2]='0';
                    s[b-3]='1';
                    s[b-4]='0';
                    s[b-5]='1';
                }
                else
                {
                    s[0]='1';
                    s[1]='0';
                    s[2]='1';
                    s[3]='0';
                    s[4]='1';

                    s[b-1]='0';
                    s[b-2]='1';
                    s[b-3]='0';
                    s[b-4]='1';
                    s[b-5]='0';
                }
            }

            for(int i=6; i<=(b-5); i++)
            {
                cout<<i<<endl;
                cin>>ans;

                s[i-1]=ans;
            }

            cout<<s<<endl;
            cin>>ans;

            if(ans=='N')
                return 0;
        }
    }

    return 0;
}

/*
01001 1010100 10100

10110 0101011 01011  1
00101 0010101 10010  2
11010 1101010 01101  3
01001 1010100 10100  4


*/
