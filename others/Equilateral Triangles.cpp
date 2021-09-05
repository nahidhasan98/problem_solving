#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    while(cin>>n)
    {
        int ans = 0;
        vector<pii>v;

        for(int i=0; i<=n; i++)
            for(int j=0; j<=n-i; j++)
                v.push_back(pii(j,i));

        for(int i=0; i<v.size(); i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                int t1 = v[j].first - v[i].first;
                int t2 = v[j].second - v[i].second;
                int t = __gcd(abs(t1),abs(t2));
                if(t > 1)
                    ans += 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//
//    int n;
//
//    while(cin>>n)
//    {
//        int sum=0;
//
//        for(int i=2; i<=n; i++)
//        {
//            for(int j=1; j<=(i-1); j++)
//            {
//                sum+=j;
//            }
//        }
//        cout<<sum*3<<endl;
//    }
//
//    return 0;
//}
