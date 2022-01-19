#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int calculate( double initial, double rate, double incoming, double target ) {
    int year = 0;

    while ( initial < target ) {
        double increasePerYear = ( ( initial * rate ) / 100 ) + incoming;
        year++;

        initial += increasePerYear;

//        double needExtra = target - initial;
//        double n = needExtra / increasePerYear;
    }

//    cout << "Years nedded = " << year << endl;
    return year;
}


int main() {
    double p, t, a, q;
    cin>> p >> t >> a >> q;

    cout << calculate( p, t, a, q ) << endl;

    return 0;
}
