#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b,sum=0;

        cin>>a>>b;

        if(a>=b)
        {
            for(int k=b+1;k<a;k++)
            {
                if(k%2!=0)
                    sum=sum+k;
            }
        }
        else
        {
            for(int k=a+1;k<b;k++)
            {
                if(k%2!=0)
                    sum=sum+k;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}




