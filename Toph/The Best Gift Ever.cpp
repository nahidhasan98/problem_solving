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
        int n, m;
        cin >> n >> m;

        long long a[ n ], b[ m ];
        for ( int i = 0; i < n; i++ ) {
            cin >> a[ i ];

            if ( i > 0 ) a[ i ] += a[ i - 1 ];
        }

        for ( int i = 0; i < m; i++ ) {
            cin >> b[ i ];

            if ( i > 0 ) b[ i ] += b[ i - 1 ];
        }

        int q, i, j, k, l;
        cin >> q;

        cout << "Case " << t << ":" << endl;
        for ( int ii = 0; ii < q; ii++ ) {
            cin >> i >> j >> k >> l;
            i--;
            j--;
            k--;
            l--;

            long long asum, bsum;

            if ( i == 0 ) asum = a[ j ];
            else asum = a[ j ] - a[ i - 1 ];

            if ( k == 0 ) bsum = b[ l ];
            else bsum = b[ l ] - b[ k - 1 ];

            long long res = asum * bsum;

            //cout << asum space bsum << endl;
            cout << res << endl;
        }
    }

    return 0;
}
