#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int ar[2000];
    map<long long int,long long int>mp;
    ar[1]=1;
    mp[ar[1]]=1;
    long long int con=1,ck=2;
    while(1)
    {
        if(mp[ar[con]*2]!=1)
        {
            ar[ck]=ar[con]*2;
            ck++;
            mp[ar[con]*2]=1;
        }
        if(mp[ar[con]*3]!=1)
        {
            ar[ck]=ar[con]*3;
            ck++;
            mp[ar[con]*3]=1;
        }
        if(mp[ar[con]*5]!=1)
        {
            ar[ck]=ar[con]*5;
            ck++;
            mp[ar[con]*5]=1;
        }

        con++;
        if(ck>=1501)
            break;
    }
    sort(ar,ar+ck);
// for(int i=1;i<=;i++)
// cout<<ar[i]<<" ";
    int n;
    while(cin>>n)
    {
        cout<<ar[n]<<endl;
    }
    return 0;
}
