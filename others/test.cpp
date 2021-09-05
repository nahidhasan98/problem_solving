#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

string decToBin ( long long n ) {
	string s = "";
    int r;

    while ( n != 0 ) {
        r = n % 2;
        s += r + 48;
        n /= 2;
    }
    reverse ( s.begin(), s.end() );

    return s;
}

long long binToDec ( string s ) {
    long long res = 0, powerTwo = 1;

    for ( int i = s.size()-1; i >= 0; i-- ) {
        if(s[i]=='1') res += powerTwo;

        powerTwo *= 2;
    }
    return res;
}

long long powerTwo ( int power ) {
    long long res = 1;

    for ( int i = 1; i <= power; i++ ) res *= 2;

    return res;

}

int main() {
    long long n;

    while ( cin >> n ) {
        cout << decToBin ( 576460752303423483+n ) <<endl;
    }

    return 0;
}
//0 1 2 3 4 5 6 7 134,217,728
//1 2 3 4 6 7 8 9
/*
2 3 2 2
1 1
2 2
2 1
2 2
*/
