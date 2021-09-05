#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        string a,b,c,d;
        cin>>a>>b>>c>>d;

        if(a==c || a==d || b==c || b==d)
            cout<<"Possible"<<endl;
        else
            cout<<"Oh no!, such a shame"<<endl;
    }

    return 0;
}
