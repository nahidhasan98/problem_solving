#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n;
        cin >> n;

        int a[n];
        for ( int i = 0; i < n; i++ ) cin >> a[i];

        sort ( a, a + n );

        int first = 0, last = n-1, diff = 1000000005;
        for ( int i = 0; i < n - 1; i++ ) {
            int curr = a[i+1] - a[i];
            if ( curr < diff ) {
                first = i;
                last = i+1;
                diff = curr;
            }
        }

        cout << a[first];
        for ( int i = first+1; i < n; i++ ) {
            if ( i != first && i != last ) cout << ' ' <<a[i];
        }
        for ( int i = 0; i < first; i++ ) {
            if ( i != first && i != last ) cout << ' ' <<a[i];
        }
        if ( first != last ) cout << ' ' <<a[last];

        cout << endl;
    }

    return 0;
}
