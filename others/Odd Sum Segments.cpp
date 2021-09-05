#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    for(int j=1; j<=q; j++)
    {
        int n,k,d,odd=0;
        cin>>n>>k;

        vector<int>v;

        for(int i=1; i<=n; i++)
        {
            cin>>d;

            if(d%2!=0)
            {
                v.push_back(i);
                odd++;
            }
        }
        if(odd>=k && k%2==odd%2)
        {
            cout<<"YES"<<endl;

            if(k==1)
                cout<<n<<endl;
            else
            {
                cout<<v[0];
                for(int i=1; i<k-1; i++)
                    cout<<' '<<v[i];
                cout<<' '<<n<<endl;
            }
        }
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
