#include<bits/stdc++.h>
using namespace std;

struct st
{
    int id,disFromSource;
};

int allVisited[100000+5];

st bfs(vector<vector<int> >&path,int source,int n)
{
    queue<int>q;
    q.push(source);
    allVisited[source]=1;

    int visited[n+1];
    memset(visited,0,sizeof(visited));

    visited[source]=1;

    int dis[n+1];
    memset(dis,0,sizeof(dis));

    dis[source]=0;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(int i=0; i<path[f].size(); i++)
        {
            int next=path[f][i];

            if(visited[next]!=1)
            {
                q.push(next);
                visited[next]=1;
                dis[next]=dis[f]+1;

                allVisited[next]=1;
            }
        }
    }

    st temp;
    temp.id=source,temp.disFromSource=0;

    for(int i=1; i<=n; i++)
    {
        if(dis[i]>temp.disFromSource)
        {
            temp.disFromSource=dis[i];
            temp.id=i;
        }
    }

    return temp;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int T=1; T<=t; T++)
    {
        memset(allVisited,0,sizeof(allVisited));

        int n,m;
        scanf("%d%d",&n,&m);

        vector<vector<int> >path(n+1);
        int u,v;

        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);

            path[u].push_back(v);
            path[v].push_back(u);
        }

        vector<int>level;
        for(int i=1; i<=n; i++)
        {
            if(allVisited[i]!=1)
            {
                st part=bfs(path,i,n);
                st full=bfs(path,part.id,n);

                int lvl=full.disFromSource;

                level.push_back(lvl);
            }
        }
        sort(level.begin(),level.end());

//        for(int i=0; i<level.size(); i++)
//        {
//            cout<<"Level= "<<level[i]<<endl;
//        }
//        cout<<"Level= "<<level<<endl;

        int q,k;
        scanf("%d",&q);

        cout<<"Case "<<T<<":"<<endl;
        for(int i=1; i<=q; i++)
        {
            scanf("%d",&k);
            int counter=0;

            if(k>n)
                printf("impossible\n");
            else
            {
                for(int j=level.size()-1; j>=0; j--)
                {
                    if(k<=level[j]+1)
                    {
                        counter+=k-1;
                        k-=min(k,level[j]+1);
                        break;
                    }
                    else
                    {
                        k-=level[j]+1;
                        counter+=level[j];
                        //printf("%d\n",level+((k-(level+1))*2));
                    }
                }
                if(k>0)
                    printf("%d\n",counter+(k*2));
                else
                    printf("%d\n",counter);
            }
        }
    }

    return 0;
}
