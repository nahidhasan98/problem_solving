
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,m,u,v,w;
        cin>>n>>m;

        int graph[n+1][n+1];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                graph[i][j]=1e7;
            //graph[j][i]=1e7;
        }

        for(int i=1; i<=m; i++)
        {
            cin>>u>>v>>w;

            graph[u][v]=min(graph[u][v],w);
            graph[v][u]=min(graph[v][u],w);
        }

        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }

        if(graph[1][n]>=1e7)
            cout<<"Case "<<t<<": Impossible"<<endl;
        else
            cout<<"Case "<<t<<": "<<graph[1][n]<<endl;
    }

    return 0;
}
