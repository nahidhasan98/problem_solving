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
        int x;
        cin >> x;

        cout << 1 << ' ' << x - 1 << endl;
    }

    return 0;
}
