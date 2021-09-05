#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);

        if(a[n-1]>1 && a[n-2]>1)
        {
            int total=a[n-2]-1;

            cout<<min(total,n-2)<<endl;
        }
        else
            cout<<0<<endl;
    }

    return 0;
}
