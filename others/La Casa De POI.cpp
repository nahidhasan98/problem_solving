#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    long long n,m;

    while(cin>>n>>m)
    {
        vector<long long>v;
        long long num=min(n,m),sum=0;

        for(int i=1;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                v.push_back(i);

                if(i!=(num/i))
                    v.push_back(num/i);
            }
        }

        for(int i=0;i<v.size();i++)
        {
            if(n%v[i]==0 && m%v[i]==0)
                sum+=v[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}
