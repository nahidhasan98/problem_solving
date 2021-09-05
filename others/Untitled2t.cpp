#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,x,p,in=0;
    cin>>n>>x;
    p = n;

    i = p/2;
    in++;
    while(i!=p)
    {
        cout<<i<<' '<<p<<' '<<in<<endl;
        if(x>i)
        {
            in++;
            i=i+((p-i)/2);
        }
        else if(x<=i)
        {
            p = i;
            in++;
            if(i%2!=0)
            {
                i = (i/2)+1;
            }
            else
            {
                i = i/2;
            }
        }
        else if(x==i)
        {
            p = i;
        }
    }

    cout<<in;
}
