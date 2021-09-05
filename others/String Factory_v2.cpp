#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        string s;
        cin>>s;

        long long res=1,mod=1000000007;

        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1]) res*=25;
            else res*=abs(s[i]-s[i+1])+1;

            res%=mod;
        }

        cout<<res%mod<<endl;
    }

    return 0;
}
