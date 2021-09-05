#include<bits/stdc++.h>
using namespace std;

struct point
{
    int i,j;
};

bool operator < (point a,point b)
{
    if(a.i!=b.i)
        return a.i<b.i;
    else
        return a.j<b.j;
}
int main()
{
    int n,m;

    while(cin>>n>>m)
    {

        int a[n][m],b[n][m];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
            }
        }

        int counter=0;
        vector<point>v;
        memset(b,0,sizeof(b));

        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<m-1; j++)
            {
                if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==1 && a[i+1][j+1]==1)
                {
                    counter++;
                    point temp;

                    temp.i=i;
                    temp.j=j;
                    v.push_back(temp);

                    b[i][j]=1;
                    b[i][j+1]=1;
                    b[i+1][j]=1;
                    b[i+1][j+1]=1;
                }
                else if(a[i][j]==1 && a[i][j+1]==1 && a[i+1][j]==0 && a[i+1][j+1]==0)
                {
                    if(i-1>=0)
                    {
                        if(a[i-1][j]==1 && a[i-1][j+1]==1)
                        {
                            counter++;
                            point temp;

                            temp.i=i-1;
                            temp.j=j;
                            v.push_back(temp);

                            b[i-1][j]=1;
                            b[i-1][j+1]=1;
                            b[i][j]=1;
                            b[i][j+1]=1;
                        }
                    }
                }
                else if(a[i][j]==1 && a[i][j+1]==0 && a[i+1][j]==1 && a[i+1][j+1]==0)
                {
                    if(j-1>=0)
                    {
                        if(a[i][j-1]==1 && a[i+1][j-1]==1)
                        {
                            counter++;
                            point temp;

                            temp.i=i;
                            temp.j=j-1;
                            v.push_back(temp);

                            b[i][j-1]=1;
                            b[i][j]=1;
                            b[i+1][j-1]=1;
                            b[i+1][j]=1;
                        }
                    }
                }
            }
        }
        int flag=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]!=b[i][j])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<-1<<endl;
        else
        {
            if(v.size()>0)
            {
                sort(v.begin(),v.end());

                for(int i=1; i<v.size(); i++)
                {
                    if(v[i-1].i==v[i].i && v[i-1].j==v[i].j)
                        counter--;
                }
                int a=-1,b=-1;

                cout<<counter<<endl;
                for(int i=0; i<v.size(); i++)
                {
                    if(v[i].i!=a || v[i].j!=b)
                    {
                        cout<<v[i].i+1<<' '<<v[i].j+1<<endl;
                        a=v[i].i;
                        b=v[i].j;
                    }
                }
            }
            else
                cout<<counter<<endl;
        }
    }
    return 0;
}
/*
1 1 1
1 1 1
0 1 1

0 0 0   1 1 0
0 0 0   1 1 0
0 0 0   0 0 0

2 7
1 1 0 1 1 1 1
1 1 0 1 1 1 1

2 8
1 1 0 1 1 1 1 1
1 1 0 1 1 1 1 1
*/
