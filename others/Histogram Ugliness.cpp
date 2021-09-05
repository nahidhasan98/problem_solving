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

        int a[n];
        for ( int i = 0; i < n; i++ ) cin >> a[i];

        long long sum = a[0];
        for ( int i = 0; i < n-1; i++ ) sum += abs ( a[i] - a[i+1] );
        sum += a[n-1];

        //cout << sum << endl;

        long long del = 0;
        if ( n == 1 ) del = a[0];

        if ( n == 2 ) {
            if ( a[0] > a[1] )  del+= a[0] - a[1];
            if ( a[n-2] < a[n-1] ) del+= a[n-1] - a[n-2];
        }

        if ( n > 2 ) {
            if ( a[0] > a[1] ) {
                del+= a[0] - a[1];
                a[0] = a[1];
            }
            if ( a[n-2] < a[n-1] ) {
                del+= a[n-1] - a[n-2];
                a[n-1] = a[n-2];
            }

            for ( int i = 1; i < n-1; i++ ) {
                if ( a[i] > a[i-1] && a[i] > a[i+1] ) {
                    del += a[i] - max ( a[i-1], a[i+1] );
                    a[i] = max ( a[i-1], a[i+1] );
                }
            }
        }
        //cout << del << endl;

        cout << sum - del << endl;
    }

    return 0;
}
