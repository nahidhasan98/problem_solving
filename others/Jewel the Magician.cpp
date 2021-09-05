#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int currPosition ( int a, int b, int c ) {
    if ( a == 1 ) {
		return 1;
	} else if ( b == 1 ) {
		return 2;
	}
	return 3;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int curr = currPosition ( a, b, c );

    int s;
    cin >> s;

    int p1, p2, res[4];
    res[1] = 0, res[2] = 0, res[3] = 0;

    for ( int i = 0; i < s; i++ ) {
        cin >> p1 >> p2;

        if ( curr == p1 ) {
			curr = p2;
			//res[curr]++;
		} else if ( curr == p2 ) {
			curr = p1;
			//res[curr]++;
		}
		res[curr]++;
    }

    cout << res[1] << ' ' << res[2] << ' ' << res[3] << endl;

    return 0;
}
