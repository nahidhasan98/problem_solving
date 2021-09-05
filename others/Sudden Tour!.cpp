#include<iostream>
#include<stdio.h>
using namespace std;

struct obj
{
    int space,funVal;
};

int arr[110][100010];

int solve(int n,int c,obj item[])
{
    int i,j;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0 || j==0)
                arr[i][j]=0;
            else if(item[i-1].space<=j)
                arr[i][j]=max(item[i-1].funVal+arr[i-1][j-item[i-1].space],arr[i-1][j]);
            else
                arr[i][j]=arr[i-1][j];
        }
    }
    return arr[n][c];
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n,c;
        cin>>n>>c;

        obj item[n];

        for(int i=0;i<n;i++)
            cin>>item[i].space>>item[i].funVal;

        cout<<"Case "<<t<<": "<<solve(n,c,item)<<endl;
    }

    return 0;
}
