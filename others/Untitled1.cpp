#include<bits/stdc++.h>
using namespace std;

int n,visited[20010];;

int bfs(vector<int>vec[],int source)
{
    int even=0,odd=0;

    queue<int>q;

    q.push(source);
    visited[source]=1;

    even++;
    int distance[20010];
    distance[source]=0;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(int i=0;i<vec[f].size();i++)
        {
            if(visited[vec[f][i]]==0)
            {
                q.push(vec[f][i]);
                visited[vec[f][i]]=1;

                distance[vec[f][i]]=distance[f]+1;

                if(distance[vec[f][i]]%2==0)
                    even++;
                else
                    odd++;
            }
        }
    }

    return max(even,odd);
}

int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        cin>>n;

        vector<int>v[20010];
        memset(visited,0,sizeof(visited));

        int x,y;
        vector<bool>arr(20010,0);

        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;

            arr[x]=true;
            arr[y]=true;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        int res=0;

        for(int j=0;j<=20010;j++)
        {
            if(arr[j]==1)
            {
                if(visited[j]==0)
                {
                    res=res+bfs(v,j);
                }
            }

        }

        printf("Case %d: %d\n",T,res);
    }

    return 0;
}
