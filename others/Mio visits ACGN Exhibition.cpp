#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

long long n, m, p, q, mod = 998244353, res = 0;
int grid[ 510 ][ 510 ];

void dp( int r, int c, int zero, int one ) {
    if ( r == n && c == m ) return;

    if ( grid[ r ][ c ] == 1 ) one++;
    else zero++;

    if ( r == n-1 && c == m-1 ) {
        if ( zero >= p && one >= q ) res++;
        res %= mod;
        return;
    }

    if ( r+1 < n ) dp( r+1, c, zero, one );
    if ( c+1 < m ) dp( r, c+1, zero, one );
}

int main() {
    cin >> n >> m >> p >> q;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ )
            cin >> grid[ i ][ j ];
    }

    dp( 0, 0, 0, 0);

    cout << res << endl;

    return 0;
}
