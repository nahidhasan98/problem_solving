#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;

    while(cin>>m>>n)
    {
        if(m==0 && n==0)
            break;

        int a[m][n],b[m][n];

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
                b[i][j]=a[i][j];
            }
        }

        for(int i=1; i<n; i++)
            b[0][i]+=b[0][i-1];

        for(int i=1; i<m; i++)
            b[i][0]+=b[i-1][0];

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
                b[i][j]+=(b[i][j-1]+b[i-1][j])-b[i-1][j-1];
        }

//        cout<<endl;
//        for(int i=0; i<m; i++)
//        {
//            for(int j=0; j<n; j++)
//            {
//                cout<<b[i][j]<<' ';
//            }
//            cout<<endl;
//        }

        int res=0,total=0,temp=0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int row=1; (i+row-1)<m; row++)
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

                        if(temp==0)
                        {
                            total=row*col;

                            res=max(res,total);
                        }
                    }
                }
            }
        }
        cout<<res<<endl;
    }

    return 0;
}
/*
3 3
1 0 0
1 0 0
1 1 1
3 3
1 0 0
1 1 1
1 1 1
*/
