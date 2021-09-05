#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    //FI FO

    int n;

    while(cin>>n)
    {
        if(n==0) break;

        int a[n],sum=0,mx=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            sum+=a[i];
            mx=max(mx,a[i]);
        }

        cout<<sum<<' '<<mx<<endl;
        for(int i=mx;i<=sum;i++)
        {
            if(sum%i==0)
            {
                cout<<i<<endl;
                break;
            }
        }
//        vector<int>v;
//        for(int i=1;i<=sqrt(sum);i++)
//        {
//            if(sum%i==0)
//            {
//                v.push_back(i);
//
//                if(i!=(sum/i)) v.push_back(sum/i);
//            }
//        }
//
//        int res=9999999;
//        for(int i=0;i<v.size();i++)
//        {
//            if(v[i]>=mx) res=min(res,v[i]);
//        }
        //cout<<res<<endl;
    }

    return 0;
}
