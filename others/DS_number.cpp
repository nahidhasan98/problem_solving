#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int n;
    cin >> n;

    int smallest = 1001, largest = 0, GCD = 1, d;

    for ( int i = 0; i < n; i++ ) {
        cin >> d;
        smallest = min( smallest, d );
        largest = max( largest, d );
    }

    GCD = __gcd( smallest, largest );

    cout << "Smallest: " << smallest << endl;
    cout << "largest: " << largest << endl;
    cout << "GCD: " << GCD << endl;

    return 0;
}
