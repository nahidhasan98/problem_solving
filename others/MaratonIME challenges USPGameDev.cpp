#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    double xr, yr, xw, yw;
    cin >> xr >> yr >> xw >> yw;

    double dr = sqrt ( ( xr * xr ) + ( yr * yr ) );
    double dw = sqrt ( ( xw * xw ) + ( yw * yw ) );

    if ( dr < dw ) cout << "Russo"  << endl;
    else if ( dw < dr ) cout << "Will" << endl;
    else cout << "Empate" << endl;

    return 0;
}
