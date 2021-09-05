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
        double a,b,c;
        cin>>a>>b>>c;

        if(b>=a && b<=c)
            cout<<ceil((a+b+c)/3)<<endl;
        else if()

        cout<<"Case "<<t<<": "<<<<endl;
    }

    return 0;
}
