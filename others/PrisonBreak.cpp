#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for (int t = 1; t <= test; t++)
    {
        int n, m, r, c;
        cin>>n>>m>>r>>c;

        int res = 0, counter;

        //upper-left
        counter = (r - 1) + (c - 1);
        res = max(res, counter);

        //upper-right
        counter = (r - 1) + (m - c);
        res = max(res, counter);

        //lower-left
        counter = (n - r) + (c - 1);
        res = max(res, counter);

        //lower-right
        counter = (n - r) + (m - c);
        res = max(res, counter);

        cout<<res<<endl;
    }

    return 0;
}

// 0 0 0 0 0
// 0 0 0 1 0
// 0 0 0 0 0
