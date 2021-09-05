/*
ID: msdipu11
PROG: palsquare
LANG: C++14
*/

/*
timus
Your JUDGE_ID: 280608OK
*/
#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define llu unsigned long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define vl vector<ll>
#define vll vector<vector<ll> >
#define vlu vector<llu>
#define vllu vector<vector<llu> >
#define pb              push_back
#define PI              acos(-1.0)
#define sc1(a)          scanf("%lld",&a)
#define sc2(a,b)        scanf("%lld %lld",&a,&b)
#define sc3(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define scd1(a)         scanf("%llf",&a)
#define scd2(a,b)       scanf("%llf %llf",&a,&b)
#define scd3(a,b,c)     scanf("%llf %llf %llf",&a,&b,&c)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(ll i=a;i<=b;i++)
#define ROF(i,a,b)      for(ll i=a;i>=b;i--)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

bool ok(ll x,ll k,vl &heights)
{

    //cout<<"x="<<x<<" k="<<k<<endl;
    ll i,j;
    vl remains(heights.size(),0);
    for(i=0;i<heights.size();i++)
    {
        k-=heights[i]/x;
        remains[i]=heights[i]%x;
        //cout<<"remains "<<remains[i]<<" for "<<remains[i]<<endl;
    }
    //cout<<"k="<<k<<endl;
    for(i=1;i<heights.size();i++)
    {
        ll need=x-remains[i-1];
        //cout<<"need ="<<need<<" for"<<i<<endl;
        if(remains[i]>=need)
        {
            k--;
            remains[i]-=need;
        }
    }
    //cout<<"last k="<<k<<endl;
    if(k<=0)
        return true;
    return false;
}

ll solve(ll k,vl &v)
{
    ll first=1,last=1e18,mid,i,j,d=0,res=0;
    while(first<=last)
    {
        if(d) break;
        if(first==last)
            d++;
        mid=(first+last)/2;
        if(ok(mid,k,v))
        {
            res=mid;
            first=mid+1;
        }
        else
            last=mid-1;
    }
    return res;
}

int main()
{
//    freopen("in.txt","r",stdin);
    ll test,t,i,j,n,k;
    sc1(test);
    while(test--)
    {
        sc2(n,k);
        vl v;
        FOR(i,1,n)
        {
            sc1(j);
            v.push_back(j);
        }
        ll x=solve(k,v);
        ll res=x*k;
        printf("%lld\n",res);
    }
}
