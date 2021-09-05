#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n][n],b[n][n];;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                b[i][j]=a[i][j];
            }
        }

        for(int i=1; i<n; i++)
            b[0][i]+=b[0][i-1];

        for(int i=1; i<n; i++)
            b[i][0]+=b[i-1][0];

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<n; j++)
                b[i][j]+=(b[i][j-1]+b[i-1][j])-b[i-1][j-1];
        }

        int sum=0,temp=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int row=1; (i+row-1)<n; row++)
                {
                    for(int col=1; (j+col-1)<n; col++)
                    {
                        if(i==0 && j==0)
                            temp=b[i+row-1][j+col-1];
                        else if(i==0)
                            temp=b[i+row-1][j+col-1]-b[i+row-1][j-1];
                        else if(j==0)
                            temp=b[i+row-1][j+col-1]-b[i-1][j+col-1];
                        else
                            temp=b[i+row-1][j+col-1]-b[i+row-1][j-1]-b[i-1][j+col-1]+b[i-1][j-1];

                        sum=max(sum,temp);
                    }
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
