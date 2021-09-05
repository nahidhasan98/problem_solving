#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,m,k;
        cin>>n>>m>>k;

        long long b[n][m];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cin>>b[i][j];
        }

        for(int i=1; i<n; i++)
            b[i][0]+=b[i-1][0];

        for(int i=1; i<m; i++)
            b[0][i]+=b[0][i-1];

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
                b[i][j]+=(b[i][j-1]+b[i-1][j])-b[i-1][j-1];
        }

//        cout<<endl;
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<m; j++)
//            {
//                cout<<b[i][j]<<' ';
//            }
//            cout<<endl;
//        }

        int res=0,sz=0,temp=0,before=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int row=1; (i+row-1)<n; row++)
                {
                    for(int col=1; (j+col-1)<m; col++)
                    {
                        if(i==0 && j==0)
                            temp=b[i+row-1][j+col-1];
                        else if(i==0)
                            temp=b[i+row-1][j+col-1]-b[i+row-1][j-1];
                        else if(j==0)
                            temp=b[i+row-1][j+col-1]-b[i-1][j+col-1];
                        else
                            temp=b[i+row-1][j+col-1]-b[i+row-1][j-1]-b[i-1][j+col-1]+b[i-1][j-1];

                        sz=row*col;

                        if(temp<=k)
                        {
                            if(sz>before)
                            {
                                before=sz;
                                res=temp;
                            }
                            else if(sz==before && temp<res)
                                res=temp;
                        }
                    }
                }
            }
        }

        cout<<"Case #"<<t<<": "<<before<<' '<<res<<endl;
    }

    return 0;
}
/*
1
5 6 15
10 1 10 20 10 10
30 1 1 5 1 1
50 1 1 20 1 1
10 5 5 10 5 1
40 10 90 1 10 10
*/
