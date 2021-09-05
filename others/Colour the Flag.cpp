#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int n, m;

char change ( char ch ) {
    if ( ch == 'W' ) return 'R';
    if ( ch == 'R' ) return 'W';
}

bool check ( string s[], char starting ) {
    bool flag = true;

    for ( int i = 0; i < n; i++ ) {
        char toBe = starting;
        for ( int j = 0; j < m; j++ ) {
            if ( s[i][j] == change ( toBe ) ) {
                flag = false;
                break;
            } else toBe = change ( toBe );
        }
        if ( !flag ) break;
        starting = change ( starting );
    }
    return flag;
}

void print ( string s[], char starting) {
    cout << "YES" << endl;

    for ( int i = 0; i < n; i++ ) {
        char toBe = starting;
        for ( int j = 0; j < m; j++ ) {
            cout << toBe;
            toBe = change ( toBe );
        }
        cout << endl;
        starting = change ( starting );
    }
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        cin >> n >> m;

        string s[n];
        for ( int i = 0; i < n; i++ ) cin >> s[i];

        if ( !check ( s, 'W' ) ) {
            if ( !check (s, 'R' ) ) cout << "NO" << endl;
            else print( s , 'R' );
        } else print( s , 'W' );
    }

    return 0;
}
