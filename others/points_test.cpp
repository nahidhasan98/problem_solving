#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t,k,i;
    cin>>t>>k;
    int a[t+1],b[t+1];
    for(i=0;i<t;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<=k;i++)
    {
        if(a[i]==b[i])
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }
      else  if(a[i]==a[t-1] && a[0]==a[1])
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }

       else if(b[i]==b[t-1] && b[0]==b[1])
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
    return 0;
}
//freopen("in.txt", "r", stdin);
