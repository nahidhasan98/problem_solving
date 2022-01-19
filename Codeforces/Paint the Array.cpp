#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n;
        cin >> n;

		long long arr[n];
		for ( int i = 0; i < n; i++ ) {
            cin >> arr[i];
		}
		long long gcdA = arr[0], gcdB = arr[1];
		for ( int i = 2; i < n; i++ ) {
            if ( i % 2 == 0 ) gcdA = __gcd( gcdA, arr[i] );
            else gcdB = __gcd( gcdB, arr[i] );
		}

		long long gcdC = __gcd(gcdA, gcdB);
		cout << gcdA space gcdB space gcdC << endl;

		else if ( gcdA == 1 ) {
            if ( gcdB == 1) cout << 0 << endl;
            else {
                cout << gcdB << endl;
            }
		} else cout << gcdA << endl;
    }

    return 0;
}
