#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

long long getSum( long long n ) {
    return ( n * ( n+1 ) ) / 2;
}

int main() {
    long long n;

    while( cin >> n )
        cout << getSum( n - 1 ) << endl;

    return 0;
}
