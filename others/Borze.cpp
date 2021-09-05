#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    string s;
    cin >> s;

    string res = "";

    for ( int i = 0; i < s.size(); i++ ) {
        if ( s[i] == '.' ) res += '0';
        else if ( s[i] == '-') {
            if ( s[i + 1] == '.' ) res += '1';
            else res += '2';

            i++;
        }
    }

    cout << res << endl;

    return 0;
}
