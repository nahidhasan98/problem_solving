#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n;
        cin >> n;

		int a[n];
		for ( int i = 0; i < n; i++ ) cin >> a[i];

		map<int,bool>mp;
		int sum = 0;

		for ( int i = n-1; i >= 0; i-- ) {
			if ( !mp[abs(a[i])] ) {
				sum += a[i];
				mp[abs(a[i])] = true;
			}
			//fmt.Printf("i=%d, sum=%d\n", i, sum)
		}

		cout << "Case " << t << ": " << sum << endl;
    }

    return 0;
}

