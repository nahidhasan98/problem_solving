#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10][10],i,j,sum=0,n=3;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>arr[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<"\t";
        cout<<"\n";
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+j==n-1)
                sum=sum+arr[i][j];
        }
    }
    cout<<endl<<"Sum of minor diagonal elements is: "<<sum<<endl;
    return 0;
}
