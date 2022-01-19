#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int n, m;
    cin >> n >> m;

    long long p[ m ], s[ m ], d, earn = 0;

    for( int i = 0; i < m; i++ ) cin >> p[ i ];
    for( int i = 0; i < m; i++ ) cin >> s[ i ];
    for( int i = 0; i < n; i++ ) {
        cin >> d;
        earn += d;
    }

    long long profit = -1, loss = 1e18, neutral = 0;

    for( int i = 0; i < m; i++ ) {
        long long cost = ( p[ i ] * n ) + s[ i ];

        if( cost == earn ) {
            neutral = 1;
        } else if ( cost < earn ) {
            long long temp = earn - cost;
            profit = max( profit, temp);
        } else {
            long long temp = cost - earn;
            loss = min( loss, temp);
        }
    }

    if ( profit > 0 ) cout << "Profit " << profit << endl;
    else if ( neutral == 1 ) cout << "Neutral" << endl;
    else cout << "Loss " << loss << endl;


    return 0;
}
