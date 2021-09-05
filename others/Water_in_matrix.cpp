#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,i,j,arr[100][100],count=0,total=0;
    
    cout<<"First enter the number of row: ";
    cin>>m;
    
    cout<<"Now enter the number of column: ";
    cin>>n;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            arr[i][j]=0;
    }
    
    cout<<"\nInitial stage of matrix:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    for(i=0;i<1;i++)
    {
        for(j=0;j<n;j=j+2)
            arr[i][j]=1;
    }
    
    for(i=0;i<m;i=i+2)
    {
        for(j=0;j<1;j++)
            arr[i][j]=1;
    }
    
    if(m%2==0 || n%2==0)
    {
        arr[m-1][n-1]=1;
        count++;
    }
        
    if(m%2==0)
        count=count+(m/2);
    else
        count=count+(m/2)+1;
    
    if(n%2==0)
        count=count+(n/2);
    else
        count=count+(n/2)+1;
    
    total=count-1;
    cout<<"\n1 will be given in minimum "<<total<<" places\n";

    cout<<"\nSecondary stage of matrix:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                if((arr[i][j-1]==1 && arr[i][j+1]==1) || (arr[i-1][j]==1 && arr[i+1][j]==1) || (arr[i-1][j]==1 && arr[i][j-1]==1))
                    arr[i][j]=1;
            }
        }
    }
    
    for(i=m-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(arr[i][j]==0)
            {
                if((arr[i-1][j]==1 && arr[i][j+1]==1) || (arr[i][j-1]==1 && arr[i+1][j]==1))
                    arr[i][j]=1;
            }
        }
    }
    
    cout<<"\nFinal stage of matrix:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}