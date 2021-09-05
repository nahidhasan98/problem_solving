#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int r, c;
char grid[25][25];
pair<int, int> S, T, B;
int dx[ 4 ] = { -1, 0, 1,  0 };
int dy[ 4 ] = {  0, 1, 0, -1 };

bool isValid( pair<int, int> a ) {
    if ( a.first >= 0 && a.first < r && a.second >= 0 && a.second < c ) return true;
    return false;
}

bool isClear( pair<int, int> a ) {
    if ( grid[ a.first ][ a.second ] != '#' && grid[ a.first ][ a.second ] != 'T' ) return true;
    return false;
}
string bfs( pair<int, int> s, pair<int, int> b ) {
    bool visited[ 25 ][ 25 ] = { false };
    queue< pair<int, int> > q;

    q.push( s );
    visited[ s.first ][ s.second ] = true;

    while ( !q.empty() ){
        pair<int, int> f;

        for ( int i = 0; i < 4; i++ ) {
            int x = f.first + dx[ i ];
            int y = f.second + dy[ i ];

            if ( isValid( { x, y } ) && isClear( { x, y } ) && !visited[ x ][ y ] )
        }
    }
}

string dfs( pair<int, int> s, pair<int, int> b ) {
    if ( s.first == b.first && s.second == b.second ) return "";

    pair<int, int> tt = b;

    for ( int i = 0; i < 4; i++ ) {
        tt.first += dx[ i ];
        tt.second += dy[ i ];

        if ( isValid( tt ) && isClear( tt ) ) {
            string s = bfs( s , tt );
            s+='W';
            b = { b.first - dx[ i ], b.second - dy[ j ] };
            s = tt;
        }
    }
}

int main() {
    int t = 0;

    while ( cin >> r >> c ) {
        if ( r == 0 && c == 0 ) break;

        for ( int i = 0; i < r; i++ ) {
            for ( int j = 0; j < c; j++ ) {
                cin >> grid[ i ][ j ];

                if ( grid[ i ][ j ] == 'S' ) S = { i, j };
                if ( grid[ i ][ j ] == 'T' ) T = { i, j };
                if ( grid[ i ][ j ] == 'B' ) B = { i, j };
            }
        }

        cout << "Maze #" << ++t << endl;
        dfs( S, B );
    }

    return 0;
}
