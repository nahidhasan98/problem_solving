#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int n;
    cin >> n;

    int a[ n ];
    bool flag = true;

    for ( int i = 0; i < n; i++ ) {
        cin >> a[ i ];

        if ( ( i > 0 )  && ( a[ i ] < a[ i-1 ] ) ) flag = false;
    }

    if ( flag ) cout << "yes\n" << 1 << ' ' << 1 << endl;
    else {
        int left = -1, right = -1, flag2 = 0;
        for ( int i = 0; i < n-1; i++ ) {
//            cout << "i=" << i space left space right ;
            if ( left != -1 && right != -1 ) {
                if ( a[ i ] > a[ i+1 ] ) {
//                    cout << " zero" << endl;
                    flag2 = 1;
                    break;
                }
            } else if ( ( left == -1 ) && ( a[ i ] > a[ i+1 ] ) ) {
//                cout << " one" << endl;
                left = i;
            } else if ( ( left != -1 ) && ( a[ i ] < a[ i+1 ] ) ) {
//                cout << " two" << endl;
                if ( a[ left ] < a[ i+1 ] ) {
                    right = i;
                } else {
                    flag2 = 1;
                    break;
                }
            } else if ( ( right != -1 ) && ( a[ i ] < a[ i+1 ] ) ) {
//                cout << " three" << endl;
                flag2 = 1;
                break;
            }
        }
//        cout << "\nlr=" << left+1 space right+1 << endl;
        if ( flag2 == 1 ) cout << "no" << endl;
        else if ( left != -1 && right == -1 ) cout << "yes\n" << left+1 << ' ' << n << endl;
        else cout << "yes\n" << left+1 << ' ' << right+1 << endl;
    }

    return 0;
}
