#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if ( s.size() == 1 ) {
        for ( int i = 0; i < k; i++ ) cout << s;
        cout << endl;
    } else {
        if ( s[0] <= s[1] ) {
            for ( int i = 0; i < k; i++ ) cout << s[0];
            cout << endl;
        } else {
            char mp[27];
            memset ( mp, 0, sizeof(mp) );

            for ( int i = 0; i < s.size()-1; i++ ) {
                if ( s[i] >= s[i+1] ) mp[s[i]] = 1;
                else {
                    //if ( s[i] > s[0] == 0 )
                }
            }
        }
    }

    return 0;
}
