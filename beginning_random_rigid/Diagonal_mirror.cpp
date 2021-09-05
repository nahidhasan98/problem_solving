#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,arr[10][10],temp,i,j,z;

    cout<<"First enter the number of row/column:\t";
    cin>>n;

    cout<<"\nNow enter the elements of array one by one:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>arr[i][j];
    }

    cout<<"\nYour entered matrix is:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<"\n";
    }

    for(i=0;i<n;i++)
    {
        z=n;
        
        for(j=0;j<n;j++)
        {   
            if(i==j)
            {
                temp=arr[i][j];
                arr[i][j]=arr[i][z-1];
                arr[i][z-1]=temp;
            }
            
            z--;
        }
    }

    cout<<"\nMirror matrix is:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<"\n";
    }

    return 0;
}
