#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    while(cin>>N)
    {
        string s;
        cin>>s;

        int z=0,e=0,r=0,o=0,n=0;

        for(int i=0; i<N; i++)
        {
            if(s[i]=='z')
                z++;
            else if(s[i]=='e')
                e++;
            else if(s[i]=='r')
                r++;
            else if(s[i]=='o')
                o++;
            else if(s[i]=='n')
                n++;
        }
        int one=min(o,min(n,e));

        o-=one;
        n-=one;
        e-=one;

        int zero=min(min(z,e),min(r,o));

        for(int i=1; i<=one; i++)
        {
            cout<<1;

            if(i<one)
                cout<<' ';
        }
        if(one>0)
            cout<<' ';
        for(int i=1; i<=zero; i++)
        {
            cout<<0;

            if(i<zero)
                cout<<' ';
        }
        cout<<endl;
    }

    return 0;
}
