#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int a,b;

    while(cin>>a>>b)
    {
        int counter=0;

        while(a<=b)
        {
            counter++;

            a*=3;
            b*=2;
        }
        cout<<counter<<endl;
    }

    return 0;
}

