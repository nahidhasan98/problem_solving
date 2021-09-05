#include<bits/stdc++.h>
using namespace std;

struct point
{
    int i,j;
};

int main()
{
    int n,m;
    cin>>n>>m;
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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]!=b[i][j])
            {
                counter++;
                point temp;

                if(i+1>=n && j+1>=m)
                {
                    temp.i=i-1;
                    temp.j=j-1;
                    v.push_back(temp);

                    b[i-1][j-1]=1;
                    b[i-1][j]=1;
                    b[i][j-1]=1;
                    b[i][j]=1;
                }
                else if(i+1>=n)
                {
                    temp.i=i-1;
                    temp.j=j;
                    v.push_back(temp);

                    b[i-1][j]=1;
                    b[i-1][j+1]=1;
                    b[i][j]=1;
                    b[i][j+1]=1;
                }
                else if(j+1>=m)
                {
                    v.push_back(i);
                    v.push_back(j-1);

                    b[i][j-1]=1;
                    b[i][j]=1;
                    b[i+1][j-1]=1;
                    b[i+1][j]=1;
                }
                else
                {
                    v.push_back(i);
                    v.push_back(j);

                    b[i][j]=1;
                    b[i][j+1]=1;
                    b[i+1][j]=1;
                    b[i+1][j+1]=1;
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
        cout<<counter<<endl;

        if(v.size()>0)
        {
            for(int i=0; i<v.size()-1; i+=2)
                cout<<v[i]+1<<' '<<v[i+1]+1<<endl;
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
*/
