#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    long long n, m, k, t;
    cin >> n >> m >> k >> t;

    long long block[k];
    long long a, b, idx = 0;

    for ( int i = 0; i < k; i++ ) {
        cin >> a >> b;
        block[idx++] = ( ( a - 1 ) * m ) + b;
    }
    sort ( block, block + k );

    for ( int i = 0; i < t; i++ ) {
        cin >> a >> b;
        long long cell = ( ( a - 1 ) * m ) + b;

        int left = 0, right = k - 1, mid, flag = 0;

        while ( left <= right ) {
            if ( right - left < 5 ) {
                int j;
                for ( j = left; j <= right; j++ ) {
                    if ( cell == block[j] ) {
                        cout << "Waste" << endl;
                        flag = 1;
                        break;
                    } else if ( cell < block[j] ) break;
                }
                if ( flag == 0 ) {
                    cell -= j;

                    if ( cell % 3 == 1 ) cout << "Carrots" << endl;
                    else if ( cell % 3 == 2 ) cout << "Kiwis" << endl;
                    else if ( cell % 3 == 0 ) cout << "Grapes" << endl;
                }
                break;
            } else {
                mid = ( left + right ) / 2;

                if ( cell == block[mid] ) {
                    cout << "Waste" << endl;
                    flag = 1;
                    break;
                }
                if ( cell < block[mid] ) right = mid - 1;
                else left = mid + 1;
            }
        }
    }

    return 0;
}
//0 1 2 3 4 5 6 7
//1 2 3 4 6 7 8 9
/*
2 3 2 2
1 1
2 2
2 1
2 2
*/
