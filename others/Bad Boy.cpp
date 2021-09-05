#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n, m, i, j;
        cin >> n >> m >> i >> j;

        cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << endl;
    }

    return 0;
}
