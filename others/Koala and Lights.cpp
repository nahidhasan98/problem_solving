#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

char table[100010][100];

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a[n], b[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i] >> b[i];
    }

    string expectedResult = "";
    for ( int i = 0; i < n; i++ ) {
        expectedResult += '1';
    }

    if ( s == expectedResult ) cout << n << endl;
    else {
        for ( int i = 0; i < n; i++ ) {
            table[0][i] = s[i];
        }

        int row = 1;
        for ( int i = 1; i < 100000; i++ ) {
            string temp = "";
            for ( int j = 0; j < n; j++ ) {
                if ( i == b[j] ) {
                    if ( table[i - 1][j] == '0') table[i][j]= '1';
                    else table[i][j]= '0';

                    b[j] += a[j];
                } else table[i][j] = table[i - 1][j];

                temp += table[i][j];
            }
            row++;
            if ( temp == expectedResult ) break;
        }

    //    for ( int i = 0; i < 50 ; i++ ) {
    //        for ( int j = 0; j < n; j++ ) {
    //            cout << table[i][j];
    //        }
    //        cout << endl;
    //    }

        int res = 0;
        for ( int i = 0; i < row ; i++ ) {
            int counter = 0;
            for ( int j = 0; j < n; j++ ) {
                if ( table[i][j] == '1' ) {
                    counter++;
                }
            }
            res = max(res, counter);
        }
        cout << res << endl;
    }

    return 0;
}
