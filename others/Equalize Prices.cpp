#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    for(int t=1;t<=q;t++)
    {
        int n,k;
        cin>>n>>k;

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);

        while(k!=0)
        {
            int res=a[0]+k;

            if(abs(res-a[n-1])<=k)
            {
                cout<<res<<endl;
                break;
            }
            else
                k--;
        }
        if(k==0)
            cout<<-1<<endl;
    }

    return 0;
}
/*
3 7
8 9 20
*/
