#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

vector< vector<int> > link( 30010 );
bool visited[ 30010 ];

int bfs( int s ) {
    int counter = 0;

    queue<int>q;
    q.push( s );
    visited[ s ] = true;
    counter++;

    while( !q.empty() ) {
        int f = q.front();
        q.pop();

        for ( int i = 0; i < link[ f ].size(); i++ ) {
            if ( !visited[ link[ f ][ i ] ] ) {
                q.push( link[ f ][ i ] );
                visited[ link[ f ][ i ] ] = true;
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        for ( int i = 0; i < link.size(); i++ ) link[ i ].clear();
        memset( visited, 0, sizeof( visited ) );

        int n, m;
        cin >> n >> m;

        int a, b;

        for ( int i = 0; i < m; i++ ) {
            cin >> a >> b;
            link[ a ].push_back( b );
            link[ b ].push_back( a );
        }

        int res = -1;

        for ( int i = 1; i <= n; i++ ) {
            if ( !visited[ i ] ) res = max( res, bfs( i ) );
        }

        cout << res << endl;
    }

    return 0;
}
