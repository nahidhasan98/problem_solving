#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    FO
    int a[ 500 ][ 500 ];
    bool val = 0;

    for ( int i = 0; i < 500; i++ ) {
        for ( int j = 0; j < 500; j++ ) {
            cout << val << ' ';
            val = !val;
        }
        cout << endl;
    }

    return 0;
}
