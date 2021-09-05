#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    long long n, a, x, y;
    cin >> n >> a >> x >> y;

    if ( n <= a ) cout << n*x << endl;
    else cout << (a * x ) + ( (n - a) * y ) << endl;

    return 0;
}
