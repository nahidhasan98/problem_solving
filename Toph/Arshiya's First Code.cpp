#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    long long n, res = 0;
    cin >> n;

    if ( n % 2 == 0 ) res = n / 2;
    else if ( n % 2 != 0 ) res =  ( n / 2 ) + 1;

    cout << res << endl;

    return 0;
}
