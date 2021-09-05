#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    FI FO
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n;
        cin>>n;

        string In,Out;
        cin>>In>>Out;

        In='0'+In;
        Out='0'+Out;

        int path[n+1][n+1]= {0};
        for(int i=1; i<n; i++)
        {
            if(Out[i]=='Y' && In[i+1]=='Y')
                path[i][i+1]=1;
        }
        for(int i=n; i>1; i--)
        {
            if(Out[i]=='Y' && In[i-1]=='Y')
                path[i][i-1]=1;
        }

        char res[n+1][n+1];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    res[i][j]='Y';

                int flag=0;
                if(i<j)
                {
                    for(int k=i; k<j; k++)
                    {
                        if(path[k][k+1]!=1)
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                else if(i>j)
                {
                    for(int k=i; k>j; k--)
                    {
                        if(path[k][k-1]!=1)
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==0)
                    res[i][j]='Y';
                else
                    res[i][j]='N';
            }
        }
//        for(int i=1; i<=n; i++)
//        {
//            for(int j=1; j<=n; j++)
//                cout<<path[i][j];
//            cout<<endl;
//        }
        cout<<"Case #"<<t<<":"<<endl;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                cout<<res[i][j];
            cout<<endl;
        }
    }

    return 0;
}
