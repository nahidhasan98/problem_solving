#include<bits/stdc++.h>
using namespace std;

int x,y,z;
int memory[6][6][6];

int solve(int x,int y,int z)
{
    if(x<0 || y<0 || z<0)
        return 0;
    if(x==0 && y==0 && z==0)
        return 1;

    if(memory[x][y][z]!=-1)
        return memory[x][y][z];

    int a=0,b=0,c=0;

    a=solve(x-1,y,z);
    b=solve(x,y-1,z);
    c=solve(x,y,z-1);

    return a+b+c;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>x>>y>>z;

        cout<<"Case #"<<t<<": "<<solve(x,y,z)<<endl;
    }

    return 0;
}
