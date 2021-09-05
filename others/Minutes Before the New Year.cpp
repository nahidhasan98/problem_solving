#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin >> test;

    for(int t=1; t<=test; t++)
    {
        int h, m;
        cin >> h>> m;

        int currMinute = ( h * 60 ) + m;

        int res = (24*60) - currMinute;

        cout << res << endl;
    }

    return 0;
}
