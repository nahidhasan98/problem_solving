#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[3010];
int memory[3010][3010];

int solve(int left,int right,int k)
{
    if((left==n-1 || right==n-1) && k==0)
        return a[right]-a[left];

    if(left>=n || right>=n || k<0)
        return 0;

    if(memory[left][k]!=-1)
        return memory[left][k];

    int x=0,y=0;

    x=(a[right]-a[left])+solve(right+1,right+1,k-1);
    y=solve(left,right+1,k);

    return memory[left][k]=min(x,y);
}

int main()
{
    while(cin>>n>>k)
    {
        memset(a,0,sizeof(a));
        memset(memory,-1,sizeof(memory));

        for(int i=0;i<n;i++)
            cin>>a[i];

        cout<<solve(0,0,k)<<endl;
    }

    return 0;
}
