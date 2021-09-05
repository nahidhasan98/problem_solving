#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        string s;
        cin>>s;
        int n=s.size();

        int a[n][n],b[n][n];

        for(int i=0; i<n; i++)
            b[0][i]=s[i]-48;

        for(int i=1; i<n; i++)
        {
            cin>>s;

            for(int j=0; j<n; j++)
            {
                b[i][j]=s[j]-48;
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

//        cout<<endl;
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//            {
//                cout<<b[i][j]<<' ';
//            }
//            cout<<endl;
//        }

        int res=0,total=0,temp=0;

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

                        total=row*col;

                        if(total==temp)
                            res=max(res,total);
                    }
                }
            }
        }
        cout<<res<<endl;

        if(t<test)
            cout<<endl;
    }

    return 0;
}
/*
3

10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110

100
100
111

100
111
111
*/
