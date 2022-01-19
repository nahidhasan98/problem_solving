#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

struct points {
    int x1, x2;
};

bool operator < ( points a, points b ) {
    if ( a.x1 != b.x1 ) return a.x1 < b.x1;
    return a.x2 < b.x2;
}

int main() {
    int n;
    cin >> n;

    points a[ n ];
    int x1, y1, x2, y2;

    for ( int i = 0; i < n; i++ ) {
        cin >> x1 >> y1 >> x2 >> y2;

        a[ i ].x1 = min( x1, x2 );
        a[ i ].x2 = max( x1, x2 );
    }

    sort( a, a+n );
    int counter = 0, last = 1;

    for ( int i = 0; i < n; i++ ) {
        if ( a[ i ].x2 > last ) {
            counter += a[ i ].x2 - max( last, a[ i ].x1 );
            last = a[ i ].x2;
        }
    }

    cout << counter << endl;

    return 0;
}
/*
5
1 2 2 2
1 4 4 4
2 3 3 3
2 6 6 6
7 9 9 9
*/
