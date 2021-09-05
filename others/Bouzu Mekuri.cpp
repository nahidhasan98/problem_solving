#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int n;
    string s;
    cin >> n >> s;

    int pos = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( s[i] == '1' ) {
            pos = i + 1;
            break;
        }
    }

    if ( pos % 2 == 0 ) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;

    return 0;
}
