#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    int res1 = d1 + d1 + d2 + d2;
    int res2 = d1 + d3 + d3 + d1;
    int res3 = d1 + d3 + d2;
    int res4 = d2 + d3 + d3 + d2;

    int res = min( res1, min( res2, min( res3, res4) ) );

    cout << res << endl;

    return 0;
}
