#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

vector<int>v;

void generateNumbers(){
    v.push_back( 0 );

    for ( int i = 1; i < 2000; i++ ) {
        int lastDigit = i % 10;

        if ( ( (i % 3) != 0 ) && lastDigit != 3 ) v.push_back( i );
    }
}

int main() {
    generateNumbers();

    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int k;
        cin >> k;

        cout << v[k] << endl;
    }

    return 0;
}
