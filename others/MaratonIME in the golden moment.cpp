#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int n;
    cin >> n;

    long long a[ n ], sum = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[ i ];
        sum += a[ i ];
    }

    long long res = 0;
    for ( int i = 0; i < n; i++ ) res += a[ i ] * ( sum - a[ i ] );

    cout << res/2 << endl;

    return 0;
}
/*
a b c d
1 3 7 11    = 22

ab+ac+ad + ab+bc+bd + ac+bc+cd + ad+bd+cd
a*(b+c+d) + b*(a+c+d)) + c*(a+b+d) + d*(a+b+c)
*/
