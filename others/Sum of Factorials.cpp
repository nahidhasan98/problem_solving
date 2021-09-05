#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long fact[22];
    fact[0]=1;

    for(int i=1; i<=20; i++)
        fact[i]=i*fact[i-1];

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        long long n;
        cin>>n;

        vector<int>v;

        for(int i=20; i>=0; i--)
        {
            if(fact[i]<=n)
            {
                v.push_back(i);
                n-=fact[i];
            }
        }

        cout<<"Case "<<t<<": ";

        if(n!=0)
            cout<<"impossible"<<endl;
        else
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                cout<<v[i]<<"!";

                if(i>0)
                    cout<<"+";
            }
            cout<<endl;
        }
    }

    return 0;
}
