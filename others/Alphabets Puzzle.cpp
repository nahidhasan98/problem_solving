#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    string s;

    while(cin>>s)
    {
        map<char,int>mp;

        for(int i=0;i<s.size();i++)
            mp[s[i]]++;

        string required="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int counter=26;

        for(int i=0;i<required.size();i++)
        {
            if(mp[required[i]]>0)
                counter--;
        }
        cout<<counter<<endl;
    }

    return 0;
}
