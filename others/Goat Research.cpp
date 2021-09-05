#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        string s[n];
        int sz=0,mx=0;
        vector<string>v;

        for(int i=0;i<n;i++)
        {
            cin>>s[i];

            sz=s[i].size();
            mx=max(mx,sz);
        }

        for(int i=0;i<n;i++)
        {
            sz=s[i].size();

            if(sz==2)
            {
                s[i]+='a';
            }
            else if(sz%2==0)
            {
                string temp="";
                temp=s[i].substr(0,sz-1);

                s[i]=temp;
            }
            for(int j=1;j<=((mx-s[i].size())/2);j++)
                cout<<' ';

            cout<<s[i]<<endl;
        }
    }

    return 0;
}
/*
5
ba
baa
baaa
baaaa
baaaaa
*/
