#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n, m;
        cin >> n >> m;

        long long buy[ n ], sell[ m ];
        for( int i = 0; i < n; i++ ) cin >> buy[ i ];
        for( int i = 0; i < m; i++ ) cin >> sell[ i ];

        sort( buy, buy + n );
        sort( sell, sell + m );

        long long res = 0;

        for( int i = 0, j = m - 1; i < n && j >= 0; i++, j-- ){
            if( buy[ i ] < sell[ j ] ) res += sell[ j ] - buy[ i ];
        }
        cout << res << endl;
    }

    return 0;
}
