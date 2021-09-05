#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n, k;
        cin >> n >> k;

        long long a[n], sum[n];
        for ( int i = 0; i < n; i++ ) cin >> a[i];

        sort(a, a+n);

        sum[0] = a[0];
        for ( int i = 1; i < n; i++ ) sum[i] = sum[i-1] + a[i];

//        for ( int i = 0; i < n; i++ ) cout << sum[i] << ' ';
//        cout << endl;

        long long res = 0;
        for ( int i = n-1; i > 0; i-=k-1 ) {
            res += sum[i];
        }
        cout << "Case " << t << ": " << res << endl;
    }

    return 0;
}
