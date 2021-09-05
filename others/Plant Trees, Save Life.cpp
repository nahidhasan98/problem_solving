#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k;
ll visited[100010];
vector<ll>graph[100010];

ll bfs(ll source,ll *a)
{
    queue<ll>q;
    q.push(source);
    visited[source]=1;

    ll sum=a[source];

    while(!q.empty())
    {
        ll f=q.front();
        q.pop();

        for(ll i=0; i<graph[f].size(); i++)
        {
            ll next=graph[f][i];

            if(visited[next]!=1)
            {
                visited[next]=1;
                q.push(next);

                sum=min(sum,a[next]);
                //cout<<"value of "<<next<<"= "<<a[next]<<" sum= "<<sum<<endl;
            }
        }
    }
    //cout<<"last= "<<sum<<endl;
    return sum;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(0);

    cin>>n>>k;
    memset(visited,-1,sizeof(visited));

    ll a[n];

    for(ll i=1; i<=n; i++)
        cin>>a[i];

    ll u,v;

    for(ll i=0; i<k; i++)
    {
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll sum=0;
    for(ll i=1; i<=n; i++)
    {
        if(visited[i]!=1)
        {
            sum+=bfs(i,a);
            //cout<<"inside= "<<sum<<endl;
        }
    }

    cout<<sum<<endl;

    return 0;
}
