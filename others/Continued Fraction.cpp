#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        long long x, y;
        cin >> x >> y;

        vector<long long> v;

        while ( true ) {
            if ( x < y ) {
                v.push_back( 0 );
                swap( x, y );
//                cout << x << ' ' << y << endl;
            } else {
                long long d = x / y;
                v.push_back( d );
                x -= y * d;
                swap( x, y );
//                cout << x << ' ' << y << endl;
            }
            if ( x == 1 ) break;
        }
        cout << v.size() - 1;
        for ( int i = 0; i < v.size(); i++ ) cout << ' ' << v[ i ];
        cout << endl;
    }

    return 0;
}
