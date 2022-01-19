#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

map<long long, int> memory;
int recur( long long num ) {
    if ( num == 1 ) return 1;
    if ( memory[ num ] != 0 ) return memory[ num ];

    if ( (num % 2) == 0 ) return memory[ num ] = recur( num/2 ) + 1;
    else return memory[ num ] = recur( (num * 3) + 1 ) + 1;
}

int main() {
    long long i, j;

    while ( cin >> i >> j ) {
        cout << i space j << ' ';

        long long a = min( i, j );
        long long b = max( i, j );

        int res = 0;
        for ( int k = a; k <= b; k++ ) res = max( res, recur( k ) );

        cout << res << endl;
    }

    return 0;
}
