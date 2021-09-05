#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,r,u,v,s,d;
        cin>>n>>r;

        int graph[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                graph[i][j]=1e7;
        }

        for(int i=0; i<r; i++)
        {
            cin>>u>>v;

            graph[u][v]=1;
            graph[v][u]=1;
        }
        cin>>s>>d;

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }

        cout<<"Case "<<t<<": "<<graph[s][d]<<endl;
    }

    return 0;
}
