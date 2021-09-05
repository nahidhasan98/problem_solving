#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,arr[10][10],temp[10][10],i,j,z;

    cout<<"First enter the number of row:\t";
    cin>>m;
    cout<<"\nNow enter the number of column:\t";
    cin>>n;

    cout<<"\nNow enter the elements of array one by one:\n";
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
        z=n;

        for(j=0;j<(n/2);j++)
        {
            temp[i][j]=arr[i][j];
            arr[i][j]=arr[i][z-1];
            arr[i][z-1]=temp[i][j];
            z--;
        }
    }

    cout<<"\nMirror matrix is:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<"\n";
    }

    return 0;
}
