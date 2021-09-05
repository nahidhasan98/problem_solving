#include<bits/stdc++.h>
using namespace std;

struct st
{
    int id,disFromSource;
};
bool operator < (st a, st b)
{
    if(a.disFromSource!=b.disFromSource)
        return a.disFromSource<b.disFromSource;
    else
        return a.id<b.id;
}

int n;
vector<vector<int> >path(1000+5);
bool hasGf[1000+5];

void dfs(int source)
{
    stack<int>s;
    s.push(source);

    bool visited[n+1];
    memset(visited,false,sizeof(visited));

    visited[source]=true;

    int dis[n+1];
    dis[source]=0;

    while(!s.empty())
    {
        int f=s.top();
        s.pop();

        for(int i=0; i<path[f].size(); i++)
        {
            int next=path[f][i];

            if(!visited[next])
            {
                s.push(next);
                visited[next]=true;
                dis[next]=dis[f]+1;
            }
        }
    }
    vector<st>verify,temp;
    for(int i=1; i<=n; i++)
    {
        st temp;
        temp.id=i;
        temp.disFromSource=dis[i];

        verify.push_back(temp);
    }
    sort(verify.begin(),verify.end());

    for(int i=0; i<verify.size(); i++)
    {
        if(hasGf[verify[i].id])
        {
            cout<<verify[i].id<<endl;
            break;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    cin>>n;

    int u,v;

    for(int i=1; i<n; i++)
    {
        cin>>u>>v;

        path[u].push_back(v);
        path[v].push_back(u);
    }
    int q,x;
    cin>>q;

    for(int i=1; i<=q; i++)
    {
        cin>>x;
        hasGf[x]=true;
    }
    dfs(1);

    return 0;
}
