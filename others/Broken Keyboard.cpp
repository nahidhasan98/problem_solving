#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        string s,res="";
        cin>>s;

        map<char,int>good,bad;

        for(int i=0; i<s.size(); i++)
        {
            if(i<s.size() && s[i]==s[i+1])
            {
                bad[s[i]]=1;
                i++;
            }
            else
                good[s[i]]=1;
        }

        if(s.size()==1)
            res=s[0];
        else
        {
            for(char i='a'; i<='z'; i++)
            {
                if(good[i]==1)
                    res+=i;
            }
        }

        cout<<res<<endl;
    }

    return 0;
}
