#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        int a[n],pos=0,neg=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            if(a[i]%2==0)
                pos++;
            else
                neg++;
        }

        if(neg%2==0 && pos==0)
            cout<<"NO"<<endl;
        else if(neg==0 && pos>0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

    return 0;
}
