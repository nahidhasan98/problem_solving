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

        if( ( ( n * m ) % 2 ) == 0 ) cout << "Bob" << endl;
        else cout << "Alice" << endl;

    }

    return 0;
}
