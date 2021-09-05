#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[10010],in=0,out=0;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];

            if(a[i]>=10 && a[i]<=20)
                in++;
            else
                out++;
        }
        cout<<in<<" in"<<endl;
        cout<<out<<" out"<<endl;
    }

    return 0;
}
