#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

long long getSum( long long n ) {
    return ( n * ( n+1 ) ) / 2;
}

int main() {
    long long n, m;
    cin >> n >> m;

    // min 1
    long long p = n / m;
    long long res1, res2;

    if ( ( p * m ) == n ) {
        res1 = getSum( p - 1 ) * m;
    } else {
        res1 = getSum( p - 1 ) * (m - 1 );
        long long q = n - ( p * ( m - 1 ) );
        res1 += getSum( q - 1 );
    }

    // min 2
    if ( ( p * m ) == n ) {
        res2 = getSum( p - 1 ) * m;
    } else {
        p++;
        res2 = getSum( p - 1 ) * ( m - 1 );
        long long q = n - ( p * ( m - 1 ) );
        res2 += getSum( q - 1 );
    }
    cout << min( res1, res2 ) << ' ';

    // max
    p = n - ( m - 1 );
    cout << getSum( p - 1 ) << endl;

    return 0;
}
