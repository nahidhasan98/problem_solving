#include<bits/stdc++.h>
using namespace std;

int n,m,k,res=0,found[6][6] = {0},dis[6][6] = {0},flag=0;
char ar[110][110];
vector<int>vec[4];

struct st
{
    int row,col;
};
st kTarget[6];

struct combo
{
    int i,j,dis;
};

bool isValid(int row,int col)
{
    if(row>=0 && row<n && col>=0 && col<m)
        return true;
    else
        return false;
}

combo BFS(st source, st target)
{
    combo tmp;
    tmp.dis=-1;

    int vis[110][110],lev[110][110];
    memset(vis,0,sizeof(vis));
    memset(lev,0,sizeof(lev));

    queue<st>q;
    q.push(source);
    vis[source.row][source.col]=1;

    int x[4]= {0,-1,0,1};
    int y[4]= {1,0,-1,0};

    while(!q.empty())
    {
        st f;
        f=q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int row=f.row+x[i],col=f.col+y[i];

            if(isValid(row,col) && vis[row][col]==0)
            {
                if(ar[row][col]=='.' || ar[row][col]=='@')
                {
                    if(row==target.row && col==target.col && found[row][col]==0)
                    {
                        //cout<<"info="<<row<<' '<<col<<endl;
                        found[row][col]=1;
                        vis[row][col]=1;
                        res+=lev[f.row][f.col]+1;

                        tmp.i=row;
                        tmp.j=col;
                        tmp.dis=res;

                        return tmp;
                    }
                    else
                    {
                        st temp;
                        temp.row=row;
                        temp.col=col;
                        q.push(temp);

                        vis[row][col]=1;
                        lev[row][col]=lev[f.row][f.col]+1;
                    }
                }
            }
        }
    }

    return tmp;
}

void getDis()
{
    for(int i=0; i<k; i++)
    {
        for(int j=i+1; j<=k; j++)
        {
            res=0;
            memset(found,0,sizeof(found));

            combo recv=BFS(kTarget[i],kTarget[j]);

            if(recv.dis==-1)
                flag=1;

            dis[i][j]=dis[j][i]=recv.dis;

            vec[i].push_back(dis[i][j]);
        }
    }
}

int getRes()
{
    int res1,res2,res3,res4,res5,res6,res7,res8,res9,res10,res11,res12;
    int res13,res14,res15,res16,res17,res18,res19,res20,res21,res22,res23,res24;

    if(k==1)
    {
        cout<<dis[0][1]<<endl;
    }
    else if(k==2)
    {
        res1=dis[0][1]+dis[1][2];
        res2=dis[0][2]+dis[2][1];

        cout<<min(res1,res2);
    }
    else if(k==3)
    {
        res1=dis[0][1]+dis[1][2]+dis[2][3];
        res2=dis[0][1]+dis[1][3]+dis[3][2];
        res3=dis[0][2]+dis[2][3]+dis[3][1];
        res4=dis[0][2]+dis[2][1]+dis[1][3];
        res5=dis[0][3]+dis[3][1]+dis[1][2];
        res6=dis[0][3]+dis[3][2]+dis[2][1];

        cout<<min(res1,min(res2,min(res3,min(res4,min(res5,res6)))));
    }
    else if(k==4)
    {
        res1=dis[0][1]+dis[1][2]+dis[2][3]+dis[3][4];
        res2=dis[0][1]+dis[1][2]+dis[2][4]+dis[4][3];
        res3=dis[0][1]+dis[1][3]+dis[3][4]+dis[4][2];
        res4=dis[0][1]+dis[1][3]+dis[3][2]+dis[2][4];
        res5=dis[0][1]+dis[1][4]+dis[4][2]+dis[2][3];
        res6=dis[0][1]+dis[1][4]+dis[4][3]+dis[3][2];

        res7=dis[0][2]+dis[2][3]+dis[3][4]+dis[4][1];
        res8=dis[0][2]+dis[2][3]+dis[3][1]+dis[1][4];
        res9=dis[0][2]+dis[2][4]+dis[4][3]+dis[3][1];
        res10=dis[0][2]+dis[2][4]+dis[4][1]+dis[1][3];
        res11=dis[0][2]+dis[2][1]+dis[1][3]+dis[3][4];
        res12=dis[0][2]+dis[2][1]+dis[1][4]+dis[4][3];

        res13=dis[0][3]+dis[3][1]+dis[1][2]+dis[2][4];
        res14=dis[0][3]+dis[3][1]+dis[1][4]+dis[4][2];
        res15=dis[0][3]+dis[3][2]+dis[2][4]+dis[4][1];
        res16=dis[0][3]+dis[3][2]+dis[2][1]+dis[1][4];
        res17=dis[0][3]+dis[3][4]+dis[4][2]+dis[2][1];
        res18=dis[0][3]+dis[3][4]+dis[4][1]+dis[1][2];

        res19=dis[0][4]+dis[4][1]+dis[1][2]+dis[2][3];
        res20=dis[0][4]+dis[4][1]+dis[1][3]+dis[3][2];
        res21=dis[0][4]+dis[4][2]+dis[2][3]+dis[3][1];
        res22=dis[0][4]+dis[4][2]+dis[2][1]+dis[1][3];
        res23=dis[0][4]+dis[4][3]+dis[3][2]+dis[2][1];
        res24=dis[0][4]+dis[4][3]+dis[3][1]+dis[1][2];

        int t1=min(res1,min(res2,min(res3,min(res4,min(res5,min(res6,min(res7,min(res8,min(res9,min(res10,min(res11,res12)))))))))));
        int t2=min(res13,min(res14,min(res15,min(res16,min(res17,min(res18,min(res19,min(res20,min(res21,min(res22,min(res23,res24)))))))))));

        cout<<min(ti,t2)<<endl;
    }
}

int main()
{
    while(cin>>n>>m)
    {
        res=0,flag=0;
        memset(found,0,sizeof(found));

        if(n==0 && m==0)
            break;

        st source,target;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>ar[i][j];

                if(ar[i][j]=='@')
                {
                    source.row=i;
                    source.col=j;
                }
            }
        }

        kTarget[0].row=source.row;
        kTarget[0].col=source.col;

        cin>>k;
        int a,b;
        for(int i=1; i<=k; i++)
        {
            cin>>a>>b;
            kTarget[i].row=a-1;
            kTarget[i].col=b-1;
        }

        getDis();

        if(flag==1)
            cout<<-1<<endl;
        else
        {
            getRes();
        }
    }

    return 0;
}
/*
2 3
##@
#.#
1
2 2

4 4
#@##
....
####
....
2
2 1
2 4

1 6
..@...
3
1 1
1 4
1 6

0 0
*/
