#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int T=1; T<=t; T++)
    {
        long long n;
        cin>>n;

        long long a[n],b[n],sum=0;
        int ax=0,ay=0,bx=0,by=0;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            sum+=a[i];

            if(a[i]%2==0)
                ax++;
            else
                ay++;
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];

            sum+=b[i];

            if(b[i]%2==0)
                bx++;
            else
                by++;
        }

        cout<<(sum-(abs(ax-bx)))/2<<endl;
    }

    return 0;
}
/*
10
3
4 5 6
1 2 3
5
4 8 6 4 1
2 5 7 4 7
6
2 4 6 8 6 2
3 7 5 8 8 4
*/
