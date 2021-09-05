#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=n-1;j>=i;j--)
                cout<<' ';
            for(int j=1;j<=i;j++)
            {
                if(j==i)
                    cout<<"*"<<endl;
                else
                    cout<<"* ";
            }
        }
    }

    return 0;
}
