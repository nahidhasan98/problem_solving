#include<bits/stdc++.h>
using namespace std;

int n,k,m;
int memory[55][55][55][3];

int solve(int tn,int tk,int curr)
{
    if((tn==0) && (tk==0))
        return 1;
    if(tn<0 || tk<0)
        return 0;

    for(int j=1; j<=m; j++)
    {
        if(memory[tn][tk][j][curr]!=-1)
            return memory[tn][tk][j][curr];

        int x=0,y=0;

        if(curr==1)
        {
            //x=solve(tn-j,tk,1);
            y=solve(tn-j,tk-1,0);
        }
        else if(curr==0)
        {
            x=solve(tn-j,tk-1,1);
            //y=solve(tn-j,tk,0);
        }
        cout<<"Hello"<<endl;

        return memory[tn][tk][j][curr]=x+y;
    }
}

int main()
{
    int t;
    cin>>t;

    memset(memory,-1,sizeof(memory));

    for(int T=1; T<=t; T++)
    {
        cin>>n>>k>>m;

        cout<<"Case "<<T<<": "<<solve(n,k,0)<<endl;
    }

    return 0;
}
/*
6
7 4 3
7 4 2
7 3 2
10 1 10
10 2 5
10 2 7
*/
