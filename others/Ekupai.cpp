#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int check(string s)
{
    int num=0;

    for(int i=0; i<s.size(); i++)
    {
        num*=10;
        num+=s[i]+48;
        num%=6;
    }
    if(num==0)
        return 1;
    else
        return 0;
}

int main()
{
//    FI FO
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        string s,res="";
        cin>>s;

        if(s[s.size()-1]!='*' && (s[s.size()-1]-48)%2!=0)
            res="-1";
        else
        {
            int allstar=1;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]!='*')
                {
                    allstar=0;
                    break;
                }
            }

            if(allstar)
            {
                for(int i=0; i<s.size(); i++)
                {
                    if(i==0 && s.size()==1)
                        res+='0';
                    else if(i==0 && s.size()>1)
                        res+='1';
                    else if(i==s.size()-1)
                        res+='2';
                    else
                        res+='0';
                }
            }
            else
            {
                int num=0,ind=-1,j,jj=0,flag=0,last,temp;

                for(int i=s.size()-1; i>=0; i--)
                {
                    if(s[i]=='*')
                    {
                        ind=i;
                        break;
                    }
                }
                if(ind==-1)
                {
                    if(check(s))
                        res=s;
                    else
                        res="-1";
                }
                else if(ind==0)
                {
                    jj=1;

                    for(j=jj; j<=9; j++)
                    {
                        num=j;
                        //cout<<"Num= "<<num<<endl;
                        for(int i=ind+1; i<s.size(); i++)
                        {
                            if(s[i]=='*')
                                num=(num*10)+0;
                            else
                                num=(num*10)+(s[i]-48);

                            num%=6;
                            //cout<<j<<' '<<i<<' '<<num<<endl;
                        }
                        if(num==0)
                        {
                            flag=1;
                            last=j;
                            break;
                        }
                    }
                    if(flag==0)
                        res="-1";
                    else
                    {
                        s[0]=last+48;
                        res=s;
                    }
                }
                else if(ind==s.size()-1)
                {
                    if(s[0]=='*')
                        s[0]='1';

                    for(int i=0; i<s.size()-1; i++)
                    {
                        num=(num*10)+(s[i]-48);

                        num%=6;
                        //cout<<j<<' '<<i<<' '<<num<<endl;
                    }

                    temp=num;
                    for(int j=0; j<=9; j++)
                    {
                        num=temp;
                        num=(num*10)+j;
                        num%=6;

                        if(num==0)
                        {
                            flag=1;
                            last=j;
                            break;
                        }
                    }
                    if(flag==0)
                        res="-1";
                    else
                    {
                        for(int i=0; i<s.size(); i++)
                        {
                            if(i==0 && s[i]=='*')
                                res+='1';
                            else if(i==ind)
                                res+=last+48;
                            else if(s[i]=='*')
                                res+='0';
                            else
                                res+=s[i];
                        }
                    }
                }
                else
                {
                    if(s[0]=='*')
                        s[0]='1';

                    num=s[0]-48;

                    //cout<<"s= "<<s[0]<<endl;
                    for(int i=1; i<ind; i++)
                    {
                        if(s[i]=='*')
                            num=(num*10)+0;
                        else
                            num=(num*10)+(s[i]-48);

                        num%=6;
                    }
                    int temp=num;

                    for(j=0; j<=9; j++)
                    {
                        num=temp;
                        num=(num*10)+j;
                        //cout<<"Num= "<<num<<endl;
                        for(int i=ind+1; i<s.size(); i++)
                        {
                            num=(num*10)+(s[i]-48);

                            num%=6;
                            //cout<<j<<' '<<i<<' '<<num<<endl;
                        }
                        if(num==0)
                        {
                            flag=1;
                            last=j;
                            break;
                        }
                    }
                    if(flag==0)
                        res="-1";
                    else
                    {
                        for(int i=0; i<s.size(); i++)
                        {
                            if(i==0 && s[i]=='*')
                                res+='1';
                            else if(i==ind)
                                res+=last+48;
                            else if(s[i]=='*')
                                res+='0';
                            else
                                res+=s[i];
                        }
                        //cout<<"s= "<<s[0]<<endl;
                    }
                }
            }
        }

        cout<<res<<endl;
    }

    return 0;
}
