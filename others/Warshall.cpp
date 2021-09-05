#include<bits/stdc++.h>
using namespace std;

int min(int a, int b);

int main()
{
    int i,j,k,m,q[10][10],w[10][10],inf=999999;

    cout<<"First enter the number of node:\t";
    cin>>m;
    cout<<"\nNow enter the given path:\n";

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
            cin>>w[i][j];
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(w[i][j]==0)
                q[i][j]=inf;
            else
                q[i][j]=w[i][j];
        }
    }
    for(k=1;k<=m;k++)
    {
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
                q[i][j]=min(q[i][j],q[i][k]+q[k][j]);
        }
    }
    cout<<"\nShortest path is:\n\n";
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
            cout<<q[i][j]<<"\t";
        cout<<endl;
    }

    return 0;
}
int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}
