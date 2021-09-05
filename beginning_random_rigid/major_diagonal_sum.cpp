#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10][10],i,j,sum=0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cin>>arr[i][j];
    }

    cout<<"\nYour entered matrix is:\n";

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<arr[i][j]<<"\t";
        cout<<"\n";
    }


    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==j)
                sum=sum+arr[i][j];
        }
    }

    cout<<endl<<"Sum of major diagonal elements is: "<<sum<<endl;

    return 0;
}
