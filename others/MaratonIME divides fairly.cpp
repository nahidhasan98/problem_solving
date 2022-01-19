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
        long long a, b;
        cin >> a >> b;

        if ( (a == b) || (abs(a-b) == 1) ) cout << "Ok" << endl;
        else {
            long long div = ( a + b ) / 2;
            cout << div << ' ' << (a+b) - div << endl;
        }
    }

    return 0;
}
/*
a b c d
1 3 7 11    = 22

ab+ac+ad + ab+bc+bd + ac+bc+cd + ad+bd+cd
a*(b+c+d) + b*(a+c+d)) + c*(a+b+d) + d*(a+b+c)
*/
