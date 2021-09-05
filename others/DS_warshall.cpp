#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    int n, e;
    cin >> n >> e;

    int s, d;
    cin >> s >> d;

    int arr[n+1][n+1], inf = 1e8;

    for ( int i = 1; i <= n; i++) {
        for ( int j = 1; j <= n; j++) {
            if ( i == j ) arr[i][j] = 0;
            else arr[i][j] = inf;
        }
    }

    int u, v, w;
    for ( int i = 1; i <= e; i++) {
        cin >> u >> v >> w;
        arr[u][v] = w;
    }

    for ( int k = 1; k <= n; k++ ) {
        for ( int i = 1; i <= n; i++) {
            for ( int j = 1; j <= n; j++) {
                if ( arr[i][j] > arr[i][k] + arr[k][j] )
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    cout << arr[s][d] << endl;

    return 0;
}
