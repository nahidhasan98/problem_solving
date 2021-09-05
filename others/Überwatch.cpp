#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[300010];
int memory[300010];

int solve(int cur_pos)
{
    if(cur_pos==n-1)
        return a[n-1];
    if(cur_pos>=n)
        return 0;

    if(memory[cur_pos]!=-1)
        return memory[cur_pos];

    int x=0,y=0;

    x+=a[cur_pos]+solve(cur_pos+m);
    y+=solve(cur_pos+1);

    return memory[cur_pos]=max(x,y);
}

int main()
{
    while(cin>>n>>m)
    {
        memset(a,-1,sizeof(a));
        memset(memory,-1,sizeof(memory));

        for(int i=0;i<n;i++)
            cin>>a[i];

        int sum=0;

        int cur_pos=m;

        sum=solve(cur_pos);

        cout<<sum<<endl;
    }

    return 0;
}
