#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        string s;
        cin>>s;

        stack<char>stk;

        char c=s[0];
        stk.push(c);

        map<char,int>mp;
        map<char,int>::iterator itr;

        for(int i=1;i<s.size()-1;i++)
        {
            c=s[i];
            char temp=stk.top();

            if(c==temp)
            {
                mp[c]++;
                stk.pop();
            }
            else
            {
                mp[temp]++;
                stk.push(c);
            }
        }

        cout<<"Case "<<T<<endl;
        for(itr=mp.begin();itr!=mp.end();itr++)
            cout<<itr->first<<" = "<<itr->second<<endl;
    }

    return 0;
}
