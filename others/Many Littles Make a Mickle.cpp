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

        int res = 0;
        for ( int i = 1; i <= n; i++ ) res += i * i * m;

        cout << res << endl;
    }

    return 0;
}
