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

ll ar[10000010];

int main()
{
    ll test,t,i,j,n,k,x,a,b,c,tmp,last;
    int ind;
    sc1(test);
    FOR(t,1,test)
    {
        //memset(ar,0,sizeof(ar));

        sc2(n,k);
        sc2(x,a);
        sc2(b,c);
        last=x;

        ind=0;
        ar[ind]=last;
        ind++;

        FOR(i,1,n-1)
        {
            tmp=last*a+b;

            if(c!=0 && (tmp/c)>=1) tmp=tmp-(c*(tmp/c));

            //if(tmp>=c && c!=0) tmp%=c;
            last=tmp;

            //cout<<tmp<<endl;
            ar[ind]=tmp;
            ind++;
        }
        //cout<<ind<<endl;
        sort(ar,ar+ind);
        printf("%lld\n",ar[k-1]);
    }
}
