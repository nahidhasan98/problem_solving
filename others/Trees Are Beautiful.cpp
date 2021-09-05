#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

struct st
{
    int u,v,w,counter;
};

bool operator < (st a,st b)
{
    if(a.counter!=b.counter)
        return a.counter>b.counter;
    else
        return a.w<b.w;
}

int n;
int visited[20010];
long long counter[20010];

long long dfs(int s,vector<vector<int> >&node)
{
    int t;
    long long sum=1;

    for(int i=0; i<node[s].size(); i++)
    {
        t=node[s][i];

        if(visited[t]==0)
        {
            visited[t]=1;
            sum+=dfs(t,node);
        }
    }

    return counter[s]=sum;
}

int main()
{
    //FI

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        memset(visited,0,sizeof(visited));
        memset(counter,0,sizeof(counter));

        vector<vector<int> >node(20010);
        vector<st>edge;

        cin>>n;
        int u,v,w;
        st temp;

        for(int i=1; i<n; i++)
        {
            cin>>u>>v>>w;

            node[u].push_back(v);
            node[v].push_back(u);

            temp.u=u;
            temp.v=v;
            temp.w=w;

            edge.push_back(temp);
        }

        visited[1]=1;
        dfs(1,node);

        long long sum=0;

        for(int i=0; i<edge.size(); i++)
        {
            int up=counter[edge[i].u];
            int down=counter[edge[i].v];

            int side1=min(up,down);
            int side2=n-side1;

            edge[i].counter=side1*side2;

            sum+=edge[i].w*edge[i].counter;
        }

        sort(edge.begin(),edge.end());

        long long operation=0;
        int ind=0;

        //cout<<sum<<endl;
        while(sum<0)
        {
            if(edge[ind].w<0)
            {
                double required=(abs(sum)*1.0)/edge[ind].counter;

                required=ceil(required);

                if(abs(edge[ind].w)>=required)
                {
                    operation+=required;
                    break;
                }
                else
                {
                    sum+=edge[ind].counter*abs(edge[ind].w);
                    operation+=abs(edge[ind].w);
                    ind++;
                }
            }
            else
                ind++;
        }

        cout<<"Case "<<t<<": "<<operation<<endl;
    }

    return 0;
}
/*
2
5
1 2 2
1 3 -3
2 5 -9
2 4 4
*/
