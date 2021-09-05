#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        string t;
        cin>>t;

        int m;
        cin>>m;

        long long dis[200][200],c,inf=1e8;

        for(int i=33; i<=126; i++)
        {
            for(int j=33; j<=126; j++)
            {
                dis[i][j]=inf;
            }
        }

        char a,b;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b>>c;

            dis[a][b]=min(dis[a][b],c);
        }
        for(int k=33; k<=126; k++)
        {
            for(int i=33; i<=126; i++)
            {
                for(int j=33; j<=126; j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        long long sum=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=t[i])
                sum+=dis[s[i]][t[i]];
        }
        if(sum>=inf)
            cout<<-1<<endl;
        else
            cout<<sum<<endl;
    }

    return 0;
}
