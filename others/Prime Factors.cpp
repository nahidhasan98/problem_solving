#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;

    while(cin>>n)
    {
        if(n==0)
            break;

        cout<<n<<" = ";

        if(n<0)
            cout<<"-1 x ";

        n=abs(n);

        long long z=2;

        while(z*z<=n)
        {
            //cout<<z<<endl;
            if(n%z==0)
            {
                cout<<z;
                n/=z;

                if(n>0)
                    cout<<" x ";
            }
            else
                z++;
        }
        if(n>0)
            cout<<n<<endl;
    }

    return 0;
}
