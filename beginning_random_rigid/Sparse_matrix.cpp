#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10][10],c,r,i,j,mul,zero=0;
    cout<<"Enter column number: ";
    cin>>c;
    cout<<"Enter row number: ";
    cin>>r;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            cin>>a[i][j];
    }
    mul=c*r;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            if(a[i][j]==0)
                zero++;
    }
    if(zero>mul/2)
        cout<<"Sparse matrix";
    else
        cout<<"Non sparse matrix";


}
