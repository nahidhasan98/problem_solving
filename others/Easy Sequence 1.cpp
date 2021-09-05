#include<bits/stdc++.h>
using namespace std;

int memory[50];

int solve(int n)
{
    if(n==1)
        return memory[n]=1;

    if(memory[n]!=-1)
        return memory[n];

    int x=0,y=0,temp=0;

    if(n%2==0)
    {
        temp=solve(n/2);

        x=(temp*temp)+1;

        return memory[n]=x;
    }
    else
    {
        y=(solve(n/2)*solve((n/2)+1))+2;

        return memory[n]=y;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    memset(memory,-1,sizeof(memory));

    int result[45];

    for(int i=1;i<=45;i++)
        int x=solve(i);

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        for(int i=1;i<=45;i++)
        {
            if(memory[i]==n)
            {
                cout<<"Case "<<t<<": "<<i<<endl;
                break;
            }
        }
    }

    return 0;
}
