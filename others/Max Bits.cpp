#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

#define FI freopen ( "in.txt", "r", stdin );
#define FO freopen ( "out.txt", "w", stdout );

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

bool isAllDigitsOne ( long long r ) {
    string s1 = decToBin ( r );
    string s2 = decToBin ( ++r );

    if ( s1.size() == s2.size() ) return false; //r is like: 1011
    else return true;                           //r is like: 1111
}

string replaceZeroWithOneFromLast ( string s ) {
	for ( int i = s.size() - 1; i >= 0; i-- ) {
		if ( s[i] == '0' ) {
			s[i] = '1';
			break;
		}
	}
	return s;
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        long long l, r;
		cin >> l >> r;

		if ( ( l == r ) || isAllDigitsOne ( r ) ) {
			cout << r << endl;
			continue;
		}

		string s1 = decToBin ( r );
		int maxPossibleDigit = s1.size();

		if ( ( l == 0 ) && ( r > 0 ) ) {
			maxPossibleDigit--;                                 //lower the digit by 1 . like: 1011 -> 111 (4 digit to 3 digit)
			long long ans = powerTwo ( maxPossibleDigit ) - 1;  //for 3 digit, 2^3 = 8 . 8 - 1 = 7 which is 111
			cout << ans << endl;

			continue;
		}

		//in normal case like: l & r both are > 0 and l != r
        string s2 = decToBin ( l );
		int minPossibleDigit = s2.size();

		if ( minPossibleDigit != maxPossibleDigit ) {
			maxPossibleDigit--;                                 //lower the digit by 1 of r
			long long ans = powerTwo ( maxPossibleDigit ) - 1;  //for 3 digit, 2^3 = 8 . 8 - 1 = 7 which is 111
			cout << ans << endl;
		} else {
			string s = decToBin ( l );
			long long curr = l, ans;

			while ( curr <= r ) {
                ans = curr;
                s = replaceZeroWithOneFromLast ( s );       // 1001101001 -> 1001101011
                curr = binToDec ( s );
			}

			cout << ans << endl;
		}
    }

    return 0;
}
/*
576460752303423486 1000000000000000000
576460752303423486 936463254927549952
576460752303423486 576460752303423487
*/

/*
00000000 =  0 log2() = undefined
00000001 =  1 log2() = 0 + 1 = 1
00000010 =  2 log2() = 1 + 1 = 2
00000011 =  3 log2() = 1 + 1 = 2
00000100 =  4 log2() = 2 + 1 = 3
00000101 =  5 log2() = 2 + 1 = 3
00000110 =  6 log2() = 2 + 1 = 3
00000111 =  7 log2() = 2 + 1 = 3
00001000 =  8 log2() = 3 + 1 = 4
00001001 =  9 log2() = 3 + 1 = 4
00001010 = 10 log2() = 3 + 1 = 4
00001011 = 11 log2() = 3 + 1 = 4
00001100 = 12 log2() = 3 + 1 = 4
00001101 = 13 log2() = 3 + 1 = 4
00001110 = 14 log2() = 3 + 1 = 4
00001111 = 15 log2() = 3 + 1 = 4
00010000 = 16 log2() = 4 + 1 = 5
*/
