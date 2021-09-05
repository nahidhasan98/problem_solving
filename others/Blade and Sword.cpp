#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int row,col;
};
int m,n;
char grid[210][210];
int visited[210][210],dis[210][210],special[210][210],vis2nd[210][210];
vector<cell>tele;

int valid(int i,int j)
{
    if((i>=0 && i<m) && (j>=0 && j<n))
        return 1;
    else
        return 0;
}

void bfs(cell source)
{
    queue<cell>q;
    q.push(source);

    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
    memset(special,0,sizeof(special));
    memset(vis2nd,0,sizeof(vis2nd));

    visited[source.row][source.col]=1;
    dis[source.row][source.col]=0;

    int x[4]= {-1,0,1,0};
    int y[4]= {0,1,0,-1};

    while(!q.empty())
    {
        cell f=q.front();
        q.pop();

        cell next;

        if(grid[f.row][f.col]=='P' || grid[f.row][f.col]=='.')
        {
            for(int i=0; i<4; i++)
            {
                next.row=f.row+x[i];
                next.col=f.col+y[i];

                if(valid(next.row,next.col) && visited[next.row][next.col]==0 && grid[next .row][next.col]!='#')
                {
                    q.push(next);
                    visited[next.row][next.col]=1;

                    dis[next.row][next.col]=dis[f.row][f.col]+1;
                }
            }
        }
        else if(grid[f.row][f.col]=='*')
        {
            if(visited[f.row][f.col]==1)
            {
                for(int i=0; i<tele.size(); i++)
                {
                    next.row=tele[i].row;
                    next.col=tele[i].col;

                    if(visited[next.row][next.col]<=1 && (next.row!=f.row || next.col!=f.col))
                    {
                        q.push(next);
                        visited[next.row][next.col]=2;

                        vis2nd[next.row][next.col]=dis[f.row][f.col]+1;
                    }
                }
                special[f.row][f.col]=1;
            }
            else if(visited[f.row][f.col]==2)
            {
                if(special[f.row][f.col]==0)
                {
                    for(int i=0; i<tele.size(); i++)
                    {
                        next.row=tele[i].row;
                        next.col=tele[i].col;

                        if(visited[next.row][next.col]<=1 && (next.row!=f.row || next.col!=f.col))
                        {
                            q.push(next);
                            visited[next.row][next.col]=2;

                            if(dis[f.row][f.col]==0)
                                vis2nd[next.row][next.col]=vis2nd[f.row][f.col]+1;
                            else
                                vis2nd[next.row][next.col]=dis[f.row][f.col]+1;
                        }
                    }
                    special[f.row][f.col]=1;
                }
                for(int i=0; i<4; i++)
                {
                    next.row=f.row+x[i];
                    next.col=f.col+y[i];

                    if(valid(next.row,next.col) && visited[next.row][next.col]==0 && grid[next .row][next.col]!='#')
                    {
                        q.push(next);
                        visited[next.row][next.col]=1;

                        dis[next.row][next.col]=vis2nd[f.row][f.col]+1;
                    }
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        tele.clear();

        cin>>m>>n;

        cell source,des;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>grid[i][j];

                if(grid[i][j]=='P')
                {
                    source.row=i;
                    source.col=j;
                }
                else if(grid[i][j]=='D')
                {
                    des.row=i;
                    des.col=j;
                }
                else if(grid[i][j]=='*')
                {
                    cell temp;

                    temp.row=i;
                    temp.col=j;

                    tele.push_back(temp);
                }
            }
        }

        bfs(source);

        if(dis[des.row][des.col]==0)
            cout<<"Case "<<t<<": impossible"<<endl;
        else
            cout<<"Case "<<t<<": "<<dis[des.row][des.col]<<endl;
    }

    return 0;
}
/*
66
4 10
##########
#.P..#*..#
#*......D#
##########
3 9
#########
#P.#..D.#
#########
4 11
###########
#P...#.*..#
#.*..#.*D.#
###########
4 11
###########
#P.....*..#
#.*....*D.#
###########
4 11
###########
#P.D...*..*
#.*....#.*.
###########
4 11
###########
#P*D*..*..*
#.*....#.*.
###########
1 13
*..P...D....*
*/
