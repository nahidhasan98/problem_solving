#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int arr[110][110];
        int m;

        memset(arr,0,sizeof(arr));

        if(n==0)
            return 0;
        else
        {
            if(n%2==0)
            {
                m=n/2;

                for(int i=1;i<=m;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(i==j)
                            arr[i][j]=i;
                        else
                            arr[i][j]=min(i,j);
                    }
                }
                int d=0;
                for(int i=m+1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        arr[i][j]=arr[m-d][j];
                    }
                    d++;
                }
                for(int i=1;i<=n;i++)
                {
                    d=0;

                    for(int j=m+1;j<=n;j++)
                    {
                        arr[i][j]=arr[i][m-d];
                        d++;
                    }
                }
            }
            else
            {
                m=(n+1)/2;

                for(int i=1;i<=m;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(i==j)
                            arr[i][j]=i;
                        else
                            arr[i][j]=min(i,j);
                    }
                }
                int d=1;
                for(int i=m+1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        arr[i][j]=arr[m-d][j];
                    }
                    d++;
                }
                for(int i=1;i<=n;i++)
                {
                    d=1;

                    for(int j=m+1;j<=n;j++)
                    {
                        arr[i][j]=arr[i][m-d];
                        d++;
                    }
                }
            }

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    //if(arr[i][j]==100)
                      //  cout<<arr[i][j]<<' ';
                    if(arr[i][j]>9 && arr[i][j]<100)
                    {
                        if(j!=n)
                            cout<<" "<<arr[i][j]<<" ";
                        else
                            cout<<" "<<arr[i][j];
                    }
                    else
                    {
                        if(j!=n)
                            cout<<"  "<<arr[i][j]<<" ";
                        else
                            cout<<"  "<<arr[i][j];
                    }
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }

    return 0;
}
