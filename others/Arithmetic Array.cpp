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

        int d, sum = 0;

        for ( int  i= 0; i < n; i++ ) {
            cin >> d;
            sum += d;
        }

        if ( sum == n ) cout << 0 << endl;
        else if ( sum < n ) cout << 1 << endl;
        else cout << sum - n << endl;
    }

    return 0;
}

/*
3
-1 0 2 3
*/
