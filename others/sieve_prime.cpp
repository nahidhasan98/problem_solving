#include <bits/stdc++.h>
using namespace std;

void Sieve(int n);

int main()
{
    int n;
    cout<<"Enter an integer: ";
    cin>>n;

    Sieve(n);

    return 0;
}
void Sieve(int n)
{
    int prime[n],p,i,k;

    for(k=1;k<=n;k++)
        prime[k]=1;

    for (p=2; p<=sqrt(n); p++)
    {
        if (prime[p]==1)
        {
            for (i=p*2;i<=n;i=i+p)
                prime[i]=0;
        }
    }

    cout<<endl<<"Prime numbers from 1 to "<<n<<" are:"<<endl;
    for (p=2;p<=n;p++)
    {
        if (prime[p])
          cout<<p<<" ";
    }
    cout<<endl;
}
