#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        string layout, s;
        cin >> layout >> s;

        map<char, int> val;
        for ( int i = 0; i < layout.size(); i++ ) val[ layout[i] ] = i + 1;

        int res = 0;
        for ( int i = 0; i < s.size()-1; i++ )
            res += abs( val[ s[ i ] ] - val[ s[ i+1 ] ] );

        cout << res << endl;
    }

    return 0;
}
