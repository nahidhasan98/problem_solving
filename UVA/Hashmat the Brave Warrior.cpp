#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    long long a, b;

    while ( cin >> a >> b ) {
        if ( a >= b ) cout << (a - b) << endl;
        else cout << (b - a) << endl;
    }

    return 0;
}
