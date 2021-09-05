#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n;
        cin >> n;

        for ( int i = 1; i <= n; i++ ) {
            cout << i;

            if ( i != n ) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
