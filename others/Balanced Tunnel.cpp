#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n],b[n];

        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];

        int counter=0,ai=0,skip[n]={0};
        for(int i=0;i<n;i++)
        {
            //cout<<a[ai]<<' '<<b[i]<<endl;
            if(skip[a[ai]]==1)
            {
                ai++;
                i--;
            }
            else if(a[ai]==b[i])
                ai++;
            else
            {
                skip[b[i]]=1;
                counter++;
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}
