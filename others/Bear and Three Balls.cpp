#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n],flag=0;
        map<int,int>mp;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            mp[a[i]]=1;
        }

        for(int i=0; i<n; i++)
        {
            if(mp[a[i]+1]==1 && mp[a[i]+2]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
