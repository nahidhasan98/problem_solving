#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10][10],i,j,m=2,n=4,temp[10][10];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cin>>arr[i][j];
    }

    cout<<"\nYour entered matrix is:\n";

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<"\n";
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            temp[j][i]=arr[i][j];
        }
    }

    cout<<"\nTranspose matrix is:\n";

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<temp[i][j]<<"\t";
        cout<<"\n";
    }

    return 0;
}
