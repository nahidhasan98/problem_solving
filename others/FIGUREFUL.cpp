#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    map<int,map<int,string> >mp;
    int a,b;
    string s;

    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>s;

        mp[a][b]=s;
    }

    int t;
    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;

        cout<<mp[a][b]<<endl;
    }

    return 0;
}
