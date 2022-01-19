#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n;
		cin >> n;

		string s[n];
		for ( int i = 0; i < n-2; i++ ) cin >> s[i];

		string res = s[0];
		for ( int i = 1; i < n-2; i++ ) {
			if ( res[res.size()-1] == s[i][0] ) res += s[i][1];
			else res += s[i];
		}
		if ( res.size() < n ) res += "a";

		cout << res << endl;
    }

    return 0;
}
