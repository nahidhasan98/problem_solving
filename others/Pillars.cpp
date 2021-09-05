#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n],pos,value=0;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            if(a[i]>value)
            {
                pos=i;
                value=a[i];
            }
        }
        int flag=0;
        for(int i=pos; i>0; i--)
        {
            if(a[i]<=a[i-1])
            {
                flag=1;
                break;
            }
        }
        for(int i=pos; i<=n-2; i++)
        {
            if(a[i]<=a[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

    return 0;
}
