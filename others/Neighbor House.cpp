#include<bits/stdc++.h>
using namespace std;

int n;
int a[22][3];
int memory[22][3];

int solve(int n,int pos)
{
    if(n<1)
        return 0;
    if(n==1)
        return a[n][pos];

    if(memory[n][pos]!=-1)
        return memory[n][pos];

    int x=0,y=0;

    if(pos==1)
    {
        x=a[n][pos]+solve(n-1,2);
        y=a[n][pos]+solve(n-1,3);

        return memory[n][pos]=min(x,y);
    }
    if(pos==2)
    {
        x=a[n][pos]+solve(n-1,1);
        y=a[n][pos]+solve(n-1,3);

        return memory[n][pos]=min(x,y);
    }
    if(pos==3)
    {
        x=a[n][pos]+solve(n-1,1);
        y=a[n][pos]+solve(n-1,2);

        return memory[n][pos]=min(x,y);
    }
}

int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>n;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        }

        int sum1=solve(n,1);
        int sum2=solve(n,2);
        int sum3=solve(n,3);

        cout<<"Case "<<T<<": "<<min(sum1,min(sum2,sum3))<<endl;
    }

    return 0;
}
/*
2

4
13 23 12
77 36 64
44 89 76
31 78 45

3
26 40 83
49 60 57
13 89 99
*/
