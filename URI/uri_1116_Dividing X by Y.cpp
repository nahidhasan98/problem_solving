#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        double x,y;
        cin>>x>>y;

        if(y==0)
            cout<<"divisao impossivel"<<endl;
        else
            cout<<fixed<<setprecision(1)<<x/y<<endl;
    }

    return 0;
}

