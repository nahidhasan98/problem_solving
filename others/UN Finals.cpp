#include<bits/stdc++.h>
using namespace std;

int n,k;
vector<string>v[3];
int memory[110];

int solve(int pos,map<string,int>&mp)
{
    if(pos<0)
        return 0;
    if(memory[pos]!=-1)
        return memory[pos];

    int x=0,y=0,z=0,u;

    u=solve(pos-1,mp);

    if(mp[v[pos][0]]<k)
    {
        mp[v[pos][0]]++;
        x=1+solve(pos-1,mp);
    }

    if(v[pos][1]!=v[pos][0] && mp[v[pos][1]]<k)
    {
        mp[v[pos][1]]++;
        y=1+solve(pos-1,mp);
    }
    if(v[pos][2]!=v[pos][0] && v[pos][2]!=v[pos][1] && mp[v[pos][2]]<k)
    {
        mp[v[pos][2]]++;
        z=1+solve(pos-1,mp);
    }

    return memory[pos]=max(max(x,y),max(z,u));
}

int main()
{
    cin>>n;
    {
        memset(memory,-1,sizeof(memory));
//        for(int i=0;i<n;i++)
//            v[i].clear();

        map<string,int>mp;
        string d;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>d;
                v[i].push_back(d);
            }
        }
        cin>>k;

        cout<<solve(n-1,mp)<<endl;
    }

    return 0;
}
