#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

string sMain;

void solve(string s,int ind)
{
    if(ind>=sMain.size())
        return;

    for(int i=0; i<=s.size(); i++)
    {
        string res="";

        res+=s.substr(0,i-0);
        res+=sMain[ind];
        res+=s.substr(i);

        if(ind==(sMain.size()-1))
            cout<<res<<endl;
        else
            solve(res,ind+1);
    }
}

int main()
{
    //FI FO
    int counter=0;

    while(cin>>sMain)
    {
        string res="";
        res+=sMain[0];

        if(counter>0)
            cout<<endl;

        solve(res,1);

        counter++;
    }

    return 0;
}
