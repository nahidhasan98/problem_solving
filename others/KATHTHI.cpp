#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int r,c;

struct cell{int row,col;};

bool isValid(cell temp){
    if(temp.row>=0 && temp.row<r && temp.col>=0 && temp.col<c)  return true;
    else return false;
}

void zeroOneBFS(string graph[])
{
    int dist[r][c],inf=1e9,visited[r][c]={0};

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            dist[i][j]=inf;
    }
    dist[0][0]=0;
    visited[0][0]=1;

    cell source;
    source.row=0;
    source.col=0;

    deque<cell>dq;
    dq.push_front(source);

    while(!dq.empty()){
        cell f=dq.front();
        dq.pop_front();

        for(int i=0;i<4;i++){
            cell next;
            next.row=f.row+dx[i];
            next.col=f.col+dy[i];

            if(isValid(next)){
                if(graph[f.row][f.col]==graph[next.row][next.col]){
                    if(dist[f.row][f.col]+0<dist[next.row][next.col]){
                        dist[next.row][next.col]=dist[f.row][f.col];
                        dq.push_front(next);
                    }
                }
                else{
                    if(dist[f.row][f.col]+1<dist[next.row][next.col]){
                        dist[next.row][next.col]=dist[f.row][f.col]+1;
                        dq.push_back(next);
                    }
                }
            }
        }
    }
    cout<<dist[r-1][c-1]<<endl;
}
int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++){
        cin>>r>>c;

        string graph[r];
        for(int i=0;i<r;i++)    cin>>graph[i];

        zeroOneBFS(graph);
    }

    return 0;
}
