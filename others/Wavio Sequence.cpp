#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int mLeft[100010],mRight[10010];

int solveLeft(int last,int pos)
{
    if(pos==n-1)
        return 1;

    if(mLeft[pos]!=-1)
        return mLeft[pos];

    int x=0,y=0;

    if(last>a[pos])
        x=1+solveLeft(a[pos],pos+1);

    y=solveLeft(last,pos+1);

    cout<<x<<' '<<y<<endl;
    return mLeft[pos]=max(x,y);
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        memset(mLeft,-1,sizeof(mLeft));

        cin>>n;

        for(int i=0;i<n;i++)
            cin>>a[i];

        solveLeft(1e9,0);

        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<mLeft[i]<<endl;

        //cout<<"Case "<<t<<": "<<<<endl;
    }

    return 0;
}
