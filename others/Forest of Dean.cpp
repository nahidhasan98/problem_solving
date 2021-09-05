#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

struct st
{
    int pos,val;
};

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,h;
        cin>>n>>h;

        int a[n],counter=0,mn=1e9+1,mx=-1;
        map<st,int>mp;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            mp[a[i]]++;

            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        sort(a,a+n);

        st b[n];
        for(int i=0;i<n;i++)
        {
            b[i].pos=1;
            b[i].val=a[i];
        }

        int curr=-1,need,next;
        for(int i=0; i<=n; i++)
        {
            if(curr==-1)
            {
                curr=a[i];
            }
            else
            {
                need=curr+1;
                next=a[i];

                if(mp[need]<=0)
                {
                    counter++;
                    curr=-1;
                }
                else
                {
                    if(need==next)
                    {
                        curr=need;
                        m[need]--;
                    }
                    else
                    {
                        curr=need;
                        mp[need]--;
                        abreak=i--;
                    }
                }
            }
        }

        if(counter==h)
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }

    return 0;
}
