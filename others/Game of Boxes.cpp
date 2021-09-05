#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long n;
        cin>>n;

        long long mxH=-1,mxL=-1,mxW=-1,sumH=0,sumL=0,sumW=0,h,l,w;

        for(int i=0;i<n;i++)
        {
            cin>>h>>l>>w;

            mxH=max(mxH,h);
            mxL=max(mxL,l);
            mxW=max(mxW,w);

            sumH+=h;
            sumL+=l;
            sumW+=w;
        }

        long long res1=sumH*mxL*mxW;
        long long res2=mxH*sumL*mxW;
        long long res3=mxH*mxL*sumW;

        cout<<min(res1,min(res2,res3))<<endl;
    }

    return 0;
}
