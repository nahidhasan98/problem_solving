#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<cstring>
#include<queue>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

vector< vector<int> > roads( 3000 );
vector< vector<int> > costs( 3000 );
bool visited[ 3000 ];
map<string, int> cityNumber;
map<string, int> ::iterator itr;
int idx = 0;
priority_queue< pair< int, pair< int, int > > > pq;

void pushToPQ( int s ) {
    for ( int i = 0; i < roads[ s ].size(); i++ ) {
        pq.push( { costs[ s ][ i ] * ( -1 ), { s, roads[ s ][ i ] } } );
    }
}
int solve( int s ) {
    int total = 0;
    visited[ s ] = true;
    pushToPQ( s );

    while ( !pq.empty() ) {
        pair< int, pair< int, int > > f = pq.top();
        pq.pop();

        if ( !visited[ f.second.second ] ) {
            visited[ f.second.second ] = true;
            total += f.first * ( -1 );

            pushToPQ( f.second.second );
        }
    }

    return total;
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        for ( int i = 0; i < roads.size(); i++ ) roads[ i ].clear();
        for ( int i = 0; i < costs.size(); i++ ) costs[ i ].clear();
        memset( visited, 0, sizeof( visited ) );
        cityNumber.clear();
        pq = priority_queue< pair< int, pair< int, int > > >();

        int m;
        cin >> m;

        string a, b;
        int cost, u, v;

        for ( int i = 0; i < m; i++ ) {
            cin >> a >> b >> cost;

            if ( cityNumber [ a ] == 0 ) cityNumber[ a ] = ++idx;
            if ( cityNumber [ b ] == 0 ) cityNumber[ b ] = ++idx;

            u = cityNumber[ a ];
            v = cityNumber[ b ];

            roads[ u ].push_back( v );
            costs[ u ].push_back( cost );

            roads[ v ].push_back( u );
            costs[ v ].push_back( cost );

        }

        cout << "Case "<< t << ": ";

        int res = solve( u );
        int flag = 0;

        for ( itr = cityNumber.begin(); itr != cityNumber.end(); itr++ ) {
            if ( !visited[ cityNumber[ itr->first ] ] ) {
                flag = 1;
                break;
            }
        }

        if ( flag == 1 ) cout << "Impossible" << endl;
        else cout << res << endl;
    }

    return 0;
}
