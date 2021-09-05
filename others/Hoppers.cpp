#include<bits/stdc++.h>
using namespace std;

struct st
{
    int root,sz;
};

int visited[500010],dis[500010];
vector<vector<int> >graph(500010);

int compCount(int source)
{
    int counter=0;

    queue<int>q;
    q.push(source);
    visited[source]=1;
    counter++;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(int i=0;i<graph[f].size();i++)
        {
            if(visited[graph[f][i]]!=1)
            {
                visited[graph[f][i]]=1;
                q.push(graph[f][i]);
                counter++;
            }
        }
    }
    return counter;
}
int need(int source)
{
    int res=0;

    for(int i=0;i<graph[source].size();i++)
    {
        int next=graph[source][i];

        if(visited[next]==1)
        {
            int before=dis[next];
            dis[next]=dis[source]+1;

            int cycleLength=dis[next]-before;

            if(cycleLength%2==0)
                continue;
            else if(cycleLength%2!=0)
                return res=1;
        }
        else
        {
            visited[next]=1;
            dis[next]=dis[source]+1;

            for(int j=0;j<graph[next].size();j++)
                res=+need(graph[next][j]);
        }
    }
    return res;
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        memset(visited,0,sizeof(visited));
        memset(dis,0,sizeof(dis));

        for(int i=1;i<=n;i++)
            graph[i].clear();

        int u,v;

        for(int i=0;i<m;i++)
        {
            cin>>u>>v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<st>component;
        st temp;
        int totalComp=0;

        for(int i=1;i<=n;i++)
        {
            if(visited[i]!=1)
            {
                temp.root=i;
                temp.sz=compCount(i);

                component.push_back(temp);
                totalComp++;
            }
        }
        memset(visited,0,sizeof(visited));
        int flag=0;

        for(int i=0;i<component.size();i++)
        {
            if(visited[component[i].root]!=1 && component[i].sz>2)
            {
                visited[component[i].root]=1;
                dis[component[i].root]=0;

                int temp=need(component[i].root);
                //cout<<component[i].root<<' '<<temp<<endl;

                if(temp>0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<totalComp-1<<endl;
        else
            cout<<1+(totalComp-1)<<endl;
    }

    return 0;
}
