#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n,k;
        cin>>n>>k;

        string s,ss="";
        cin>>s;

        ss+=s[0];

        map<char,int>mp;

        for(int i=1;i<s.size();i++)
        {
            for(int j=0;j<ss.size();j++)
            {
                if(s[i]==ss[j])
                {
                    mp[s[i]]++;
                    break;
                }
            }
            ss+=s[i];
            if(ss.size()>k)
                ss=ss.substr(1);
        }

        int counter=0;
        for(int i='A';i<='Z';i++)
            counter+=mp[i];

        cout<<"Case "<<t<<": "<<counter<<endl;
    }

    return 0;
}
