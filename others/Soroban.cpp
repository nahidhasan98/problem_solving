#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    map<char,string>mp;
    mp['0']="O-|-OOOO";
    mp['1']="O-|O-OOO";
    mp['2']="O-|OO-OO";
    mp['3']="O-|OOO-O";
    mp['4']="O-|OOOO-";
    mp['5']="-O|-OOOO";
    mp['6']="-O|O-OOO";
    mp['7']="-O|OO-OO";
    mp['8']="-O|OOO-O";
    mp['9']="-O|OOOO-";

    string s;
    while(cin>>s)
    {
        for(int i=s.size()-1; i>=0; i--)
        {
            cout<<mp[s[i]]<<endl;
        }
    }

    return 0;
}
