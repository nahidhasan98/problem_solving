#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        string a[n],s;
        map<string,int>mp,ck;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            cin>>s;
            ck[s]++;
        }

        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(mp[a[i]]!=ck[a[i]])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"Troll"<<endl;
        else
            cout<<"Croissant"<<endl;
    }

    return 0;
}
