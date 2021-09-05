#include<bits/stdc++.h>
using namespace std;

struct st
{
    int value,divisors;
};

vector<st>v;

bool operator < (st a,st b)
{
    if(a.divisors!=b.divisors)
        return a.divisors<b.divisors;
    else
        return a.value>b.value;
}

void solve()
{
    for(int i=1;i<=1000;i++)
    {
        int counter=0;

        for(int j=1;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                if(j*j==i)
                    counter++;
                else
                    counter+=2;
            }
        }
        st temp;
        temp.value=i;
        temp.divisors=counter;

        v.push_back(temp);
    }
}

int main()
{
    solve();

    sort(v.begin(),v.end());

//    for(int i=0;i<v.size();i++)
//        cout<<v[i].value<<' '<<v[i].divisors<<endl;

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        cout<<"Case "<<t<<": "<<v[n-1].value<<endl;
    }

    return 0;
}
