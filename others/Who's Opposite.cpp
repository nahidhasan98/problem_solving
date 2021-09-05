#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        long long a , b, c, res = -1;
        cin >> a >> b >> c;

        long long N = ( B - 1 ) + ( B - A );

        if ( C == A ) res = B;
        else if ( C == B ) res = A;
        else if ( C > A && C < B ) res = C + ( B - A );
        else if ( C > B  && C <= N ) res = C - ( B - A );

        cout << A << ' ' << B << ' ' << C << endl;
        cout << res << endl;
    }

    return 0;
}
