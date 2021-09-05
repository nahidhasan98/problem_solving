#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[110][110];
int memory[110][110];

int solve(int x,int y)
{
    if(memory[x][y]!=-1)
        return memory[x][y];

    int sum=0;
    vector<int>v;

    for(int i=x+1; i<=(x+k) && i<n ; i++)
    {
        sum=0;

        if(a[i][y]>a[x][y])
        {
            if(i==n-1)
                sum+=a[i][y];
            else
                sum+=a[i][y]+solve(i,y);
        }

        //cout<<"Sum= "<<sum<<endl;
        v.push_back(sum);
    }
    for(int i=x-1; i>=(x-k) && i>=0 ; i--)
    {
        sum=0;

        if(a[i][y]>a[x][y])
        {
            if(i==0)
                sum+=a[i][y];
            else
                sum+=a[i][y]+solve(i,y);
        }

        v.push_back(sum);
    }
    for(int i=y+1; i<=(y+k) && i<n ; i++)
    {
        sum=0;

        if(i==n-1)
            sum+=a[x][i];
        else
            sum+=a[x][i]+solve(x,i);

        v.push_back(sum);
    }
    for(int i=y-1; i>=(y-k) && i>=0 ; i--)
    {
        sum=0;

        if(i==0)
            sum+=a[x][i];
        else
            sum+=a[x][i]+solve(x,i);

        v.push_back(sum);
    }


    if(v.size()>0)
    {
        sort(v.begin(),v.end());

        cout<<"Size= "<<v.size()<<endl;

        return memory[x][y]=v[v.size()-1];
    }
    else
        return 0;
}

int main()
{
    int t;
    cin>>t;

    for(int T=1; T<=t; T++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>n>>k;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        }
        int res=a[0][0];
        res+=solve(0,0);

        if(T==t)
            cout<<res<<endl;
        else
            cout<<res<<"\n"<<endl;
    }

    return 0;
}
/*
2

3 1
1 2 5
10 11 6
12 12 7

3 1
1 2 5
5 11 6
3 12 7
*/
