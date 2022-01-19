#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int n;
    cin >> n;

    for ( int i = 0; i < ( 2 * n ); i++ ) {
        cout << i;
        if ( i != ( 2 * n ) - 1 ) cout << ' ';
    }
    cout << endl;

    return 0;
}
