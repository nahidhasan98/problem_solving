#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int q;
        cin >> q;

        for ( int i = 0; i < q; i++ ) {
            long long x, d, n;
            cin >> x >> d >> n;

            cout << ( ( n - 1 ) * d ) + x << endl;
        }
    }

    return 0;
}
