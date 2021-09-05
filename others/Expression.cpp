#include<bits/stdc++.h>
using namespace std;

struct st
{
    int left,right,ind,sz;
};

bool operator < (st a,st b)
{
    if(a.sz!=b.sz)
        return a.sz>b.sz;
    else
        return a.ind>b.ind;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        string s,reserve;
        cin>>s;
        reserve=s;

        int counter=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]==')')
                counter++;
        }

        int pos=0,neg=0,ind;

        while(counter>0)
        {
            int flag=0;

            for(int i=1; i<s.size(); i++)
            {
                if(s[i]=='(' && s[i-1]=='+')
                {
                    pos=1;
                    neg=0;
                    ind=i;
                    flag=1;
                }
                else if(s[i]=='(' && s[i-1]=='-')
                {
                    neg=1;
                    pos=0;
                    ind=i;
                    flag=1;
                }
                else if(s[i]==')')
                {
                    if(pos==1)
                    {
                        s[ind]='@';
                        s[i]='*';
                        pos=0;
                        counter-=2;
                    }
                    else if(neg==1)
                    {
                        s[ind]='@';
                        s[i]='*';
                        neg=0;
                        counter-=2;

                        for(int k=ind; k<=i; k++)
                        {
                            if(s[k]=='+')
                                s[k]='-';
                            else if(s[k]=='-')
                                s[k]='+';
                        }
                    }
                }
            }
            if(flag==0)
                break;
        }
        if(counter>0)
        {
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='(')
                    s[i]='@';
                else if(s[i]==')')
                    s[i]='*';
            }
        }
        string temp="";
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!='*')
                temp+=s[i];
        }
        s=temp;

        pos=0,neg=0;
        vector<st>pv,nv;
        st tmp;
        int flag=0;

        //cout<<s<<endl;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='+' || s[i]=='-')
            {
                flag=0;
                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j]=='@')
                    {
                        flag++;
                        continue;
                    }
                    if(s[j]=='#')
                    {
                        if(j==s.size()-1)
                        {
                            tmp.ind=i;
                            tmp.left=i+1+flag;
                            tmp.right=j;
                            tmp.sz=tmp.right-tmp.left+1;

                            if(s[i]=='+')
                                pv.push_back(tmp);
                            else if(s[i]=='-')
                                nv.push_back(tmp);

                            break;
                        }
                        continue;
                    }
                    else
                    {
                        tmp.ind=i;
                        tmp.left=i+1+flag;
                        tmp.right=j-1;
                        tmp.sz=tmp.right-tmp.left+1;

                        if(s[i]=='+')
                            pv.push_back(tmp);
                        else if(s[i]=='-')
                            nv.push_back(tmp);

                        i=j-1;
                        break;
                    }
                }
            }
        }
        flag=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='#')
            {
                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j]=='#')
                    {
                        if(j==s.size()-1)
                        {
                            tmp.ind=i;
                            tmp.left=i;
                            tmp.right=j;
                            tmp.sz=tmp.right-tmp.left+1;

                            pv.push_back(tmp);

                            break;
                        }
                        continue;
                    }
                    else
                    {
                        tmp.ind=i;
                        tmp.left=i;
                        tmp.right=j-1;
                        tmp.sz=tmp.right-tmp.left+1;

                        pv.push_back(tmp);

                        i=j-1;
                        break;
                    }
                }
            }
            else if(s[i]=='+' || s[i]=='-')
                break;
        }
        sort(pv.begin(),pv.end());
        sort(nv.begin(),nv.end());

        //cout<<pv.size()<<' '<<nv.size()<<endl;
        string digit;
        cin>>digit;

        sort(digit.begin(),digit.end());
        reverse(digit.begin(),digit.end());

        map<char,int>mp;

        for(int i=0; i<digit.size(); i++)
            mp[digit[i]]++;

        long long res=0,sum=0,td;
        ind=0;
        for(int i=0; i<pv.size(); i++)
        {
            for(int j=pv[i].left; j<=pv[i].right; j++)
            {
                s[j]=digit[ind];
                ind++;

                td=s[j]-48;
                sum=(sum*10)+td;
            }
            res+=sum;
            sum=0;
        }
        ind=digit.size()-1;
        for(int i=0; i<nv.size(); i++)
        {
            for(int j=nv[i].left; j<=nv[i].right; j++)
            {
                s[j]=digit[ind];
                ind--;

                td=s[j]-48;
                sum=(sum*10)+td;
            }
            res-=sum;
            sum=0;
        }

        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
                reserve[i]=s[i];
        }

        cout<<"Case "<<t<<":"<<endl;
        cout<<reserve<<endl;
        cout<<res<<endl;
    }

    return 0;
}
/*6-(6+8-(7+8)-9+8)-9
33+9993
*/
