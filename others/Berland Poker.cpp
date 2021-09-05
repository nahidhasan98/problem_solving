#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        double n, m, k;
        cin >> n >> m >> k;

        if ( m == 0 ) cout << 0 << endl;
        else {
            double cardsPerPlayer = n / k;

            if ( m <= cardsPerPlayer ) cout << m << endl;
            else {
                double winnerJokers = cardsPerPlayer;
                m -= cardsPerPlayer;
                k--;

                double secondMaxJokers = ceil( m / k );

                cout << winnerJokers - secondMaxJokers << endl;
            }
        }
    }

    return 0;
}
