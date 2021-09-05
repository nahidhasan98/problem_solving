#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    string s,ss;
    cin>>s;

    map<char,int>sample;

    for(int i=0;i<s.size();i++)
        sample[s[i]]=1;

    for(int i=1;i<=(17*n);i++)
        cin>>ss;

    for(int i=1;i<=q;i++)
    {
        cin>>ss;

        cout<<"Query "<<i<<": ";

        for(int j=0;j<ss.size();j++)
        {
            if(s[j]==ss[j])
                cout<<"Y";
            else
                cout<<"N";
        }
        cout<<endl;
    }

    return 0;
}
