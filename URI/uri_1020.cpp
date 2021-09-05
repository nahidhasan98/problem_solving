#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,m,y,temp;

    cin>>n;

    temp=n%365;

    y=n/365;

    m=temp/30;

    d=temp%30;

    cout<<y<<" ano(s)"<<endl<<m<<" mes(es)"<<endl<<d<<" dia(s)"<<endl;

    return 0;
}
