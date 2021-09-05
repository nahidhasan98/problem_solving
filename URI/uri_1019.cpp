#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s,m,h,temp;

    cin>>n;

    s=n%60;

    temp=n/60;

    m=temp%60;

    h=temp/60;

    cout<<h<<":"<<m<<":"<<s<<endl;

    return 0;
}
