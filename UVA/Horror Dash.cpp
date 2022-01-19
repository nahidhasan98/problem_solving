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
        int n;
        cin >> n;

        int res = 0, d;
        for ( int i = 0; i < n; i++ ) {
            cin >> d;
            res = max( res, d );
        }
        cout << "Case " << t << ": " << res << endl;
    }

    return 0;
}
