#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        double n, x;
        cin >> n >> x;

        if ( n <= 2 ) cout << 1 << endl;
        else cout << 1 + ceil((n-2) / x) << endl;
    }

    return 0;
}
