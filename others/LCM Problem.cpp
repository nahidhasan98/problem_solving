#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int l, r;
        cin >> l >> r;

        if ( ( l * 2 ) <= r ) {
            cout<< l << ' ' << l * 2 << endl;
        } else {
            cout<< -1 << ' ' << -1 << endl;
        }
    }

    return 0;
}
