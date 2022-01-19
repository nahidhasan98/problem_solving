#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    double h, u, d, f;

    while ( cin >> h >> u >> d >> f ) {
        if ( h == 0 ) break;

        double climb = 0, day = 0, fat = ( f * u ) / 100;
        while ( true ) {
            day++;

            climb += u;
            if ( climb > h ) {
                cout << "success on day " << day << endl;
                break;
            }

            climb -= d;
            if ( climb < 0 ) {
                cout << "failure on day " << day << endl;
                break;
            }

            u -= fat;
            if ( u < 0 ) u = 0;
        }
    }

    return 0;
}
