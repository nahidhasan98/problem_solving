#include<bits/stdc++.h>
using namespace std;

int a[1000010];

int main()
{
    int n;

    while(cin>>n)
    {
        if(n==0)
            break;

        memset(a,0,sizeof(a));

        int z=2,counter=0,rest=n;

        while(z*z<=n)
        {
            if(n%z==0)
            {
                n/=z;

                if(a[z]==0)
                {
                    counter++;
                    a[z]=1;
                }
            }
            else
                z++;
        }

        if(a[n]==0)
            counter++;

        cout<<rest<<" : "<<counter<<endl;
    }

    return 0;
}
