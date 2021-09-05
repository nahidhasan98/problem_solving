#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int t,a[4],counter=0;
    cin>>t;

    for(int k=1;k<=t;k++)
    {
        for(int i=0;i<4;i++) cin>>a[i];
        sort(a,a+4);

        if(a[3]>5 && a[2]>5 && a[1]>5)
            counter++;
    }

    cout<<counter<<endl;

    return 0;
}
