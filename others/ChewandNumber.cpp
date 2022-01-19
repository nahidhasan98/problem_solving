#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    string s, res = "";
    cin >> s;

    for ( int i = s.size() - 1; i >= 0; i-- ) {
        if ( s[ i ] >= '5' ) res += ( '9' - s[ i ] ) + 48;
        else res += s[ i ];
    }

    reverse( res.begin(), res.end() );

    if ( res [ 0 ] == '0' ) res[ 0 ] = s[ 0 ];

    cout << res << endl;

    return 0;
}
