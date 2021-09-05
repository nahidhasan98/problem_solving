#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10][10],n,i,j,flag=0;
    cout<<"Enter order: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>a[i][j];

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j&&a[i][j]!=0)
                flag=1;

        }
    }
    if(flag==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i<j&&a[i][j]!=0)
                    flag=2;

            }
        }

    }
    if(flag==0)
        cout<<"Upper triangle matrix\n\n";
    else if(flag==1)
        cout<<"lower triangular matrix\n\n";
    else
        cout<<"neither upper nor lower";

    if(flag==0)
    {
       for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i<=j)
                    cout<<a[i][j];
                else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    else if(flag==1)
    {
       for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>=j)
                    cout<<a[i][j];
                else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"End";

    return 0;
}
