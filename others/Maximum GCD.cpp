#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    cin.ignore();

    for(int t=1;t<=test;t++)
    {
        string s;
        getline(cin,s);

        stringstream ss(s);

        int num;
        vector<int>v;

        while(ss>>num)
            v.push_back(num);

        int res=0;

        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
                res=max(res,__gcd(v[i],v[j]));
        }

        cout<<res<<endl;
    }

    return 0;
}
